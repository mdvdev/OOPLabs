#ifndef LONGFLOAT_H
#define LONGFLOAT_H

#include <string>

class LongFloat {
private:
    std::string number;
    static constexpr int precision = 6;
public:
    LongFloat() : number("0") { }
    LongFloat(const LongFloat& rhs) : number(rhs.number) { }
    LongFloat(LongFloat&& rhs) : number(std::move(rhs.number)) { }
    explicit LongFloat(const std::string& number);

    LongFloat& operator=(double number) { this->number = std::to_string(number); return *this; }
    LongFloat& operator=(const LongFloat& rhs) { number = rhs.number; return *this; }
    LongFloat& operator=(LongFloat&& rhs) { number = std::move(rhs.number); return *this; }
    LongFloat& operator+=(const LongFloat& rhs) { *this = *this + rhs; return *this; }
    LongFloat& operator-=(const LongFloat& rhs) { *this = *this - rhs; return *this; }
    LongFloat& operator*=(const LongFloat& rhs) { *this = *this * rhs; return *this; }
    LongFloat& operator/=(const LongFloat& rhs) { *this = *this / rhs; return *this; }
    LongFloat operator+(const LongFloat& rhs) const;
    LongFloat operator-(const LongFloat& rhs) const;
    LongFloat operator*(const LongFloat& rhs) const;
    LongFloat operator/(const LongFloat& rhs) const;
    bool operator>(const LongFloat& rhs) const;
    bool operator>=(const LongFloat& rhs) const;
    bool operator==(const LongFloat& rhs) const;
    bool operator!=(const LongFloat& rhs) const;

    friend std::istream& operator>>(std::istream& is, LongFloat& number);

    explicit operator std::string() const { return number; }
private:
    void alignFractionalPart(std::string& num, size_t resultSize) const;
    void alignIntegerPart(std::string& num, size_t resultSize) const;
    int addWithCarry(int a, int b, int& carry) const;
    int subtractWithBorrow(int a, int b, int& borrow) const;
    int multiplyWithCarry(int a, int b, int& carry) const;
    void trimPrecision(std::string& num) const;
    void removeLeadingZeroes(std::string& num) const;
    void removeTrailingZeroes(std::string& num) const;
    void clearNumber(std::string& num) const;
    void alignNumbers(std::string& num1, std::string& num2) const;
    LongFloat multiplyIntegers(const std::string& num1, const std::string& num2) const;
    LongFloat divideIntegers(const std::string& num1, const std::string& num2) const;
    LongFloat addIntegers(const std::string& num1, const std::string& num2) const;
    LongFloat subtractIntegers(const std::string& num1, const std::string& num2) const;
    void eraseDot(std::string& num) const;
    LongFloat divideByTwo() const;
    std::pair<LongFloat, LongFloat> dividePartialQuotient(const LongFloat& divisor) const;
    void normalizeNumbers(std::string& num1, std::string& num2) const;
};

#endif // LONGFLOAT_H
