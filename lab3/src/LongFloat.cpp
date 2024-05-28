#include <iostream>
#include <algorithm>
#include <cassert>

#include "LongFloat.h"
#include "InvalidNumberError.h"
#include "ZeroDivisionError.h"

LongFloat::LongFloat(const std::string& number)
{
    if (number == "" || number == "-")
        throw InvalidNumberError("Error: invalid number.");

    bool dotOccured = false;
    for (size_t i = 0; i < number.length(); ++i) {
        if ((!std::isdigit(number[i]) && number[i] != '.' && number[i] != '-') ||
            (number[i] == '.' && (dotOccured || i == 0 || i == number.length() - 1 || number[i-1] == '-')) ||
            (number[i] == '-' && i != 0))
        {
            throw InvalidNumberError("Error: invalid number.");
        }
        if (number[i] == '.')
            dotOccured = true;
    }

    this->number = number;

    clearNumber(this->number);
}

void LongFloat::alignFractionalPart(std::string& num, size_t resultSize) const
{
    size_t dotPos = num.find('.');
    if (dotPos == std::string::npos) {
        num += ".";
        num += std::string(resultSize, '0');
    } else {
        size_t fracPartDigitCount = num.length() - dotPos - 1;
        if (fracPartDigitCount < resultSize)
            num += std::string(resultSize - fracPartDigitCount, '0');
        else if (fracPartDigitCount > resultSize)
            trimPrecision(num);
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

int LongFloat::multiplyWithCarry(int a, int b, int& carry) const
{
    int multiply = a * b + carry;
    carry = multiply / 10;
    return multiply % 10;
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
    auto endPos = dotPos != std::string::npos ? num.begin() + dotPos : num.end();
    auto signifPos = std::find_if(num.begin(), endPos, [](char c) { return c != '0'; });

    if (dotPos != std::string::npos)
        num = signifPos == num.begin() + dotPos ? num.substr(dotPos - 1) : num.substr(signifPos - num.begin());
    else
        num = signifPos == num.end() ? "0" : num.substr(signifPos - num.begin());
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

void LongFloat::clearNumber(std::string& num) const
{
    removeLeadingZeroes(num);
    removeTrailingZeroes(num);

    trimPrecision(num);
    removeTrailingZeroes(num);

    if (num == "-0" || num == "-0.0")
        num.erase(0, 1);
}

void LongFloat::alignNumbers(std::string& num1, std::string& num2) const
{
    size_t dotPos1 = num1.find('.');
    size_t dotPos2 = num2.find('.');
    int resultSize;

    if (dotPos1 != std::string::npos || dotPos2 != std::string::npos) {
        if (dotPos1 != std::string::npos && dotPos2 != std::string::npos)
            resultSize = std::max(num1.length() - dotPos1 - 1, num2.length() - dotPos2 - 1);
        else
            resultSize = dotPos1 == std::string::npos ? num2.length() - dotPos2 - 1 :
                             num1.length() - dotPos1 - 1;
        alignFractionalPart(num1, resultSize);
        alignFractionalPart(num2, resultSize);
    }

    resultSize = std::max(num1.length(), num2.length());

    alignIntegerPart(num1, resultSize);
    alignIntegerPart(num2, resultSize);
}

bool LongFloat::operator>(const LongFloat& rhs) const
{
    if (number[0] != '-' && rhs.number[0] == '-')
        return true;
    else if (number[0] == '-' && rhs.number[0] != '-')
        return false;

    std::string num1 = number[0] == '-' ? number.substr(1) : number;
    std::string num2 = rhs.number[0] == '-' ? rhs.number.substr(1) : rhs.number;

    size_t num1DotPos = num1.find('.');
    size_t num2DotPos = num2.find('.');

    std::string num1Integer = num1DotPos != std::string::npos ? num1.substr(0, num1DotPos) : num1;
    std::string num2Integer = num2DotPos != std::string::npos ? num2.substr(0, num2DotPos) : num2;

    // Integer part comparison
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

    // Fractional part comparison
    if (num1Fraction.length() > num2Fraction.length())
        return false;
    else if (num1Fraction.length() < num2Fraction.length())
        return true;

    return num1Fraction > num2Fraction;
}

bool LongFloat::operator>=(const LongFloat& rhs) const
{
    return *this > rhs || *this == rhs;
}

bool LongFloat::operator==(const LongFloat& rhs) const
{
    LongFloat temp = *this - rhs;
    return temp.number == "0" || temp.number == "0.0";
}

bool LongFloat::operator!=(const LongFloat& rhs) const
{
    return !(*this == rhs);
}

LongFloat LongFloat::multiplyIntegers(const std::string& num1, const std::string& num2) const
{
    std::string result;

    for (int i = num2.length() - 1; i >= 0; --i) {
        std::string current;
        int carry = 0;

        for (int j = num1.length() - 1; j >= 0; --j) {
            int a = num2[i] - '0';
            int b = num1[j] - '0';
            int multiply = multiplyWithCarry(a, b, carry);
            current += std::to_string(multiply);
        }

        if (carry) current += std::to_string(carry);
        std::reverse(current.begin(), current.end());

        if (result == "") {
            result = current;
            continue;
        }

        current += std::string(num2.length() - i - 1, '0');
        result = std::string(LongFloat(current) + LongFloat(result));
    }

    return LongFloat(result);
}

LongFloat LongFloat::divideIntegers(const std::string& num1, const std::string& num2) const
{
    std::string result;
    std::string current;
    LongFloat remainder("0");
    LongFloat dividend(num1);
    LongFloat divisor(num2);

    for (char digit : dividend.number) {
        current += digit;

        auto divResult = LongFloat(current).dividePartialQuotient(divisor);
        std::string quotient = std::string(divResult.first);
        result += quotient;

        remainder = divResult.second;
        current = std::string(remainder);
    }

    if (remainder != LongFloat("0")) {
        result += ".";

        int decimalPos = 0;
        while (decimalPos < precision) {
            remainder *= LongFloat("10");

            if (divisor > remainder) {
                result += "0";
                decimalPos++;
                continue;
            }

            auto divResult = LongFloat(remainder).dividePartialQuotient(divisor);
            std::string quotient = std::string(divResult.first);

            result += quotient;
            decimalPos++;

            remainder = divResult.second;

            if (remainder == LongFloat("0"))
                break;
        }
    }

    return LongFloat(result);
}

LongFloat LongFloat::addIntegers(const std::string& num1, const std::string& num2) const
{
    std::string result;
    int resultSize = std::max(num1.length(), num2.length());
    int carry = 0;

    for (int i = resultSize - 1; i >= 0; i--) {
        int a = num1[i] - '0';
        int b = num2[i] - '0';
        int sum = addWithCarry(a, b, carry);
        result += std::to_string(sum);
    }

    if (carry) result += std::to_string(carry);
    std::reverse(result.begin(), result.end());

    return LongFloat(result);
}

LongFloat LongFloat::subtractIntegers(const std::string& num1, const std::string& num2) const
{
    std::string result;
    int resultSize = std::max(num1.length(), num2.length());
    int borrow = 0;

    for (int i = resultSize - 1; i >= 0; i--) {
        int a = num1[i] - '0';
        int b = num2[i] - '0';
        int subtract = subtractWithBorrow(a, b, borrow);
        result += std::to_string(subtract);
    }

    std::reverse(result.begin(), result.end());

    return LongFloat(result);
}

LongFloat LongFloat::divideByTwo() const
{
    std::string result;
    int carry = 0;

    for (char digit : number) {
        int current = carry * 10 + (digit - '0');
        result += (current / 2 + '0');
        carry = current % 2;
    }

    return LongFloat(result == "" ? "0" : result);
}
std::pair<LongFloat, LongFloat> LongFloat::dividePartialQuotient(const LongFloat& divisor) const
{
    LongFloat low("0");
    LongFloat high(*this);

    while (high >= low) {
        LongFloat mid((low + high).divideByTwo());
        if (*this >= mid * divisor)
            low = mid + LongFloat("1");
        else
            high = mid - LongFloat("1");
    }

    return std::pair<LongFloat, LongFloat>{ high, *this - high * divisor };
}

void LongFloat::eraseDot(std::string& num) const
{
    size_t dotPos = num.find('.');

    if (dotPos != std::string::npos)
        num.erase(dotPos, 1);
}

void LongFloat::normalizeNumbers(std::string& num1, std::string& num2) const
{
    size_t dotPos1 = num1.find('.');
    size_t dotPos2 = num2.find('.');

    int decimalPartCount1 = dotPos1 != std::string::npos ? num1.length() - dotPos1 - 1 : 0;
    int decimalPartCount2 = dotPos2 != std::string::npos ? num2.length() - dotPos2 - 1 : 0;
    int maxDecimalPartCount = std::max(decimalPartCount1, decimalPartCount2);

    eraseDot(num1);
    eraseDot(num2);

    if (maxDecimalPartCount) {
        if (decimalPartCount1 < maxDecimalPartCount)
            num1 += std::string(maxDecimalPartCount - decimalPartCount1, '0');
        if (decimalPartCount2 < maxDecimalPartCount)
            num2 += std::string(maxDecimalPartCount - decimalPartCount2, '0');
    }
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

    alignNumbers(num1, num2);
    assert(num1.length() == num2.length());

    size_t dotPos1 = num1.find('.');
    size_t resultDotShift = dotPos1 != std::string::npos ? num1.length() - dotPos1 - 1 : 0;

    eraseDot(num1);
    eraseDot(num2);
    assert(num1.length() == num2.length());

    std::string result = std::string(addIntegers(num1, num2));
    if (resultDotShift >= result.length())
        result.insert(0, std::string(resultDotShift - result.length() + 1, '0'));

    if (resultDotShift)
        result.insert(result.length() - resultDotShift, ".");

    if (isNegative) result.insert(0, "-");

    return LongFloat(result);
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

    alignNumbers(num1, num2);
    assert(num1.length() == num2.length());

    size_t dotPos1 = num1.find('.');
    size_t resultDotShift = dotPos1 != std::string::npos ? num1.length() - dotPos1 - 1 : 0;

    eraseDot(num1);
    eraseDot(num2);
    assert(num1.length() == num2.length());

    std::string result = std::string(subtractIntegers(num1, num2));
    if (resultDotShift >= result.length())
        result.insert(0, std::string(resultDotShift - result.length() + 1, '0'));

    if (resultDotShift)
        result.insert(result.length() - resultDotShift, ".");

    if (isNegative) result.insert(0, "-");

    return LongFloat(result);
}

LongFloat LongFloat::operator*(const LongFloat& rhs) const
{
    if (rhs.number == "0" || rhs.number == "0.0" ||
        number == "0" || number == "0.0")
    {
        return LongFloat("0");
    }

    std::string num1 = number;
    std::string num2 = rhs.number;
    bool isNegative = false;

    if ((num1[0] == '-' && num2[0] != '-') || (num1[0] != '-' && num2[0] == '-'))
        isNegative = true;

    if (num1[0] == '-')
        num1.erase(0, 1);

    if (num2[0] == '-')
        num2.erase(0, 1);

    alignNumbers(num1, num2);
    assert(num1.length() == num2.length());

    size_t dotPos1 = num1.find('.');
    size_t dotPos2 = num2.find('.');
    size_t resultDotShift = (dotPos1 != std::string::npos ? num1.length() - dotPos1 - 1 : 0) +
                            (dotPos2 != std::string::npos ? num2.length() - dotPos2 - 1 : 0);

    eraseDot(num1);
    eraseDot(num2);
    assert(num1.length() == num2.length());

    std::string result = std::string(multiplyIntegers(num1, num2));
    if (resultDotShift >= result.length())
        result.insert(0, std::string(resultDotShift - result.length() + 1, '0'));

    if (resultDotShift)
        result.insert(result.length() - resultDotShift, ".");

    if (isNegative) result.insert(0, "-");

    return LongFloat(result);
}

LongFloat LongFloat::operator/(const LongFloat& rhs) const
{
    if (rhs.number == "0" || rhs.number == "0.0")
        throw ZeroDivisionError("Error: division by zero.");
    if (number == "0" || number == "0.0")
        return LongFloat("0");

    std::string num1 = number;
    std::string num2 = rhs.number;
    bool isNegative = false;

    if ((num1[0] == '-' && num2[0] != '-') || (num1[0] != '-' && num2[0] == '-'))
        isNegative = true;

    if (num1[0] == '-')
        num1.erase(0, 1);

    if (num2[0] == '-')
        num2.erase(0, 1);

    normalizeNumbers(num1, num2);

    std::string result = std::string(divideIntegers(num1,  num2));

    if (isNegative) result.insert(0, "-");

    return LongFloat(result);
}

std::istream& operator>>(std::istream& is, LongFloat& number)
{
    std::string num;
    char c;
    bool minusOccured = false;

    while (is >> c) {
        if ((!std::isdigit(c) && c != '.' && c != '-') || (c == '-' && (minusOccured || num != ""))) {
            is.unget();
            break;
        }
        if (c == '-') minusOccured = true;
        num += c;
    }

    LongFloat tempNumber(num);
    number = std::move(tempNumber);

    return is;
}
