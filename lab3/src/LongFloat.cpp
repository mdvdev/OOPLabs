#include <iostream>
#include <algorithm>

#include "LongFloat.h"

void LongFloat::alignFractionalPart(std::string& num) const
{
    size_t dotPos = num.find('.');
    if (dotPos != std::string::npos)
        num += std::string(precision - (num.length() - dotPos - 1), '0');
    else {
        num += '.';
        num += std::string(precision, '0');
    }
}

void LongFloat::alignIntegerPart(std::string& num, size_t resultSize) const
{
    if (num.length() < resultSize)
        num = std::string(resultSize - num.length(), '0') + num;
}

int LongFloat::addWithCarry(int a, int b, int& carry) const
{
    int sum = a + b + carry;
    carry = sum / 10;
    return sum % 10;
}

int LongFloat::subtractWithBorrow(int a, int b, int& borrow) const
{
    int subtract = a - b - borrow;
    if (subtract < 0) {
        subtract += 10;
        borrow = 1;
    } else
        borrow = 0;
    return subtract;
}

void LongFloat::trimPrecision(std::string& num) const
{
    size_t dotPos = num.find('.');
    if (dotPos != std::string::npos && num.length() - dotPos - 1 > precision)
        num = num.substr(0, dotPos + precision + 1);
}

void LongFloat::removeLeadingZeroes(std::string& num) const
{
    size_t dotPos = num.find('.');
    if (dotPos != std::string::npos) {
        auto signifPos = std::find_if(num.begin(), num.begin() + dotPos, [](char c) { return c != '0'; });
        num = signifPos == num.begin() + dotPos ? num.substr(dotPos - 1) : num.substr(signifPos - num.begin());
    } else {
        auto signifPos = std::find_if(num.begin(), num.end(), [](char c) { return c != '0'; });
        num = signifPos == num.end() ? "0" : num.substr(signifPos - num.begin());
    }
}

void LongFloat::removeTrailingZeroes(std::string& num) const
{
    size_t dotPos = num.find('.');
    if (dotPos == std::string::npos)
        return;

    size_t i;
    for (i = num.length() - 1; i != dotPos; --i)
        if (num[i] != '0')
            break;

    num = num[i] != '.' ? num.substr(0, i + 1) : num.substr(0, dotPos + 2);
}

bool LongFloat::operator>(const LongFloat& rhs) const
{
    if (number[0] != '-' && rhs.number[0] == '-')
        return true;
    else if (number[0] == '-' && rhs.number[0] != '-')
        return false;

    std::string num1 = number[0] == '-' ? number.substr(1) : number;
    std::string num2 = rhs.number[0] == '-' ? rhs.number.substr(1) : rhs.number;

    removeLeadingZeroes(num1);
    removeLeadingZeroes(num2);

    removeTrailingZeroes(num1);
    removeTrailingZeroes(num2);

    size_t num1DotPos = num1.find('.');
    size_t num2DotPos = num2.find('.');

    std::string num1Integer = num1DotPos != std::string::npos ? num1.substr(0, num1DotPos) : num1;
    std::string num2Integer = num2DotPos != std::string::npos ? num2.substr(0, num2DotPos) : num2;

    if (num1Integer.length() > num2Integer.length())
        return true;
    else if (num1Integer.length() < num2Integer.length())
        return false;

    if (num1Integer > num2Integer)
        return true;
    else if (num1Integer < num2Integer)
        return false;

    if (num1DotPos == std::string::npos && num2DotPos == std::string::npos)
        return false;
    else if (num1DotPos == std::string::npos && num2DotPos != std::string::npos)
        return false;
    else if (num1DotPos != std::string::npos && num2DotPos == std::string::npos)
        return num1[num1DotPos + 1] != '0';

    std::string num1Fraction = num1.substr(num1DotPos + 1);
    std::string num2Fraction = num2.substr(num2DotPos + 1);

    if (num1Fraction.length() > num2Fraction.length())
        return false;
    else if (num1Fraction.length() < num2Fraction.length())
        return true;

    return num1Fraction > num2Fraction;
}

LongFloat LongFloat::operator+(const LongFloat& rhs) const
{
    std::string num1 = number;
    std::string num2 = rhs.number;
    bool isNegative = false;

    if (num1[0] == '-' && num2[0] == '-') {
        num1.erase(0, 1);
        num2.erase(0, 1);
        isNegative = true;
    } else if (num1[0] == '-') {
        num1.erase(0, 1);
        return rhs - LongFloat(num1);
    } else if (num2[0] == '-') {
        num2.erase(0, 1);
        return *this - LongFloat(num2);
    }

    trimPrecision(num1);
    trimPrecision(num2);

    alignFractionalPart(num1);
    alignFractionalPart(num2);

    int resultSize = std::max(num1.length(), num2.length());

    alignIntegerPart(num1, resultSize);
    alignIntegerPart(num2, resultSize);

    std::string result;
    int carry = 0;

    for (int i = resultSize - 1; i >= 0; i--) {
        if (num1[i] == '.') continue;
        int a = num1[i] - '0';
        int b = num2[i] - '0';
        int sum = addWithCarry(a, b, carry);
        result += std::to_string(sum);
    }

    if (carry) result += '1';

    size_t dotPos1 = num1.find('.');
    size_t dotPos2 = num2.find('.');
    size_t dotPos = std::max(dotPos1, dotPos2);

    if (carry) dotPos++;

    std::reverse(result.begin(), result.end());

    std::string finalResult;
    finalResult += result.substr(0, dotPos);
    finalResult += ".";
    finalResult += result.substr(dotPos);
    removeLeadingZeroes(finalResult);
    if (isNegative) finalResult.insert(0, "-");

    return LongFloat(finalResult);
}

LongFloat LongFloat::operator-(const LongFloat& rhs) const
{
    std::string num1 = number;
    std::string num2 = rhs.number;
    bool isNegative = false;

    if (num1[0] == '-' && num2[0] == '-') {
        num1.erase(0, 1);
        num2.erase(0, 1);
        return LongFloat(num2) - LongFloat(num1);
    } else if (num1[0] == '-') {
        num1.erase(0, 1);
        LongFloat result = LongFloat(num1) + rhs;
        return LongFloat("-" + std::string(result));
    } else if (num2[0] == '-') {
        num2.erase(0, 1);
        return *this + LongFloat(num2);
    }

    if (LongFloat(num2) > LongFloat(num1)) {
        std::swap(num1, num2);
        isNegative = true;
    }

    trimPrecision(num1);
    trimPrecision(num2);

    alignFractionalPart(num1);
    alignFractionalPart(num2);

    int resultSize = std::max(num1.length(), num2.length());

    alignIntegerPart(num1, resultSize);
    alignIntegerPart(num2, resultSize);

    std::string result;
    int borrow = 0;

    for (int i = resultSize - 1; i >= 0; i--) {
        if (num1[i] == '.') continue;
        int a = num1[i] - '0';
        int b = num2[i] - '0';
        int subtract = subtractWithBorrow(a, b, borrow);
        result += std::to_string(subtract);
    }

    size_t dotPos1 = num1.find('.');
    size_t dotPos2 = num2.find('.');
    size_t dotPos = std::max(dotPos1, dotPos2);
    std::reverse(result.begin(), result.end());

    std::string finalResult;
    finalResult += result.substr(0, dotPos);
    finalResult += ".";
    finalResult += result.substr(dotPos);
    removeLeadingZeroes(finalResult);
    if (isNegative) finalResult.insert(0, "-");

    return LongFloat(finalResult);
}

LongFloat LongFloat::operator*(const LongFloat& rhs) const
{

}

LongFloat LongFloat::operator/(const LongFloat& rhs) const
{

}

std::istream& operator>>(std::istream& is, LongFloat& number)
{
    number.number = "";

    char c;
    bool dotOccured = false;
    bool minusOccured = false;

    while (is >> c) {
        if ((!std::isdigit(c) && c != '.' && c != '-') ||
            (c == '.' && dotOccured) ||
            (c == '-' && minusOccured) || (c == '-' && number.number != ""))
        {
            is.unget();
            break;
        }
        if (c == '.')
            dotOccured = true;
        if (c == '-')
            minusOccured = true;
        number.number += c;
    }

    if (number.number == "")
        is.setstate(std::ios_base::failbit);
    else if (number.number[number.number.size() - 1] == '.')
        number.number += '0';

    return is;
}
