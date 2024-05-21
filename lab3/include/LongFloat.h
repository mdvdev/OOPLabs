#ifndef LONGFLOAT_H
#define LONGFLOAT_H

#include <string>

class LongFloat {
private:
    std::string number;
    static constexpr int precision = 6;
public:
    LongFloat() = default;
    LongFloat(const LongFloat& rhs) : number(rhs.number) { }
    LongFloat(LongFloat&& rhs) : number(std::move(rhs.number)) { }
    explicit LongFloat(const std::string& number) : number(number) { }

    LongFloat& operator=(double number) { this->number = std::to_string(number); return *this; }
    LongFloat& operator=(const LongFloat& rhs) { number = rhs.number; return *this; }
    LongFloat& operator=(LongFloat&& rhs) { number = std::move(rhs.number); return *this; }
    LongFloat& operator+=(const LongFloat& rhs) { *this = *this + rhs; return *this; }
    LongFloat& operator-=(const LongFloat& rhs) { *this = *this - rhs; return *this; }
    LongFloat& operator*=(const LongFloat& rhs) { }
    LongFloat& operator/=(const LongFloat& rhs) { }
    LongFloat operator+(const LongFloat& rhs) const;
    LongFloat operator-(const LongFloat& rhs) const;
    LongFloat operator*(const LongFloat& rhs) const;
    LongFloat operator/(const LongFloat& rhs) const;
    bool operator>(const LongFloat& rhs) const;

    friend std::istream& operator>>(std::istream& is, LongFloat& number);

    explicit operator std::string() const { return number; }
private:
    void alignFractionalPart(std::string& num) const;
    void alignIntegerPart(std::string& num, size_t resultSize) const;
    int addWithCarry(int a, int b, int& carry) const;
    int subtractWithBorrow(int a, int b, int& borrow) const;
    void trimPrecision(std::string& num) const;
    void removeLeadingZeroes(std::string& num) const;
    void removeTrailingZeroes(std::string& num) const;
};

#endif // LONGFLOAT_H
