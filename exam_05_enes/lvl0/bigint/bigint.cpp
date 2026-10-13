#include "bigint.hpp"

// ---------- canonical form ----------
bigint::bigint() : digits("0") {}

bigint::bigint(unsigned long long n)
{
    if (n == 0)
        digits = "0";
    while (n > 0)
    {
        digits = char('0' + n % 10) + digits;
        n /= 10;
    }
}

bigint::bigint(const bigint& other) : digits(other.digits) {}

bigint& bigint::operator=(const bigint& other)
{
    if (this != &other)
        digits = other.digits;
    return *this;
}

bigint::~bigint() {}

bigint::bigint(const std::string& str)
{
    size_t i = 0;
    while (i + 1 < str.size() && str[i] == '0')
        i++;
    digits = str.empty() ? "0" : str.substr(i);
}

// ---------- addition ----------
bigint bigint::operator+(const bigint& other) const
{
    bigint result;
    result.digits = "";
    int i = digits.size() - 1; 
    int j = other.digits.size() - 1; 
    int carry = 0;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0) sum += digits[i--] - '0';
        if (j >= 0) sum += other.digits[j--] - '0';
        result.digits = char('0' + sum % 10) + result.digits;
        carry = sum / 10;
    }
    return result;
}

bigint& bigint::operator+=(const bigint& other) 
{ 
    return *this = *this + other; 
}

bigint& bigint::operator++() 
{ 
    return *this += 1; 
}

bigint  bigint::operator++(int)
{ 
    bigint t(*this); 
    ++*this; 
    return t; 
}

// ---------- digit shifts ----------
bigint bigint::operator<<(const bigint& num) const
{
    bigint result(*this);
    if (digits != "0")
        result.digits.append(num.toULL(), '0');
    return result;
}

bigint bigint::operator>>(const bigint& num) const
{
    if (num >= bigint(digits.size()))
        return bigint(0);
    bigint result;
    result.digits = digits.substr(0, digits.size() - num.toULL());
    return result;
}

bigint& bigint::operator<<=(const bigint& num) { return *this = *this << num; }
bigint& bigint::operator>>=(const bigint& num) { return *this = *this >> num; }

// ---------- comparisons ----------
bool bigint::operator==(const bigint& other) const { return digits == other.digits; }
bool bigint::operator!=(const bigint& other) const { return !(*this == other); }
bool bigint::operator<(const bigint& other) const
{
    if (digits.size() != other.digits.size())
        return digits.size() < other.digits.size();
    return digits < other.digits;
}
bool bigint::operator>(const bigint& other) const  { return other < *this; }
bool bigint::operator<=(const bigint& other) const { return !(other < *this); }
bool bigint::operator>=(const bigint& other) const { return !(*this < other); }

// ---------- utils ----------
unsigned long long bigint::toULL() const
{
    unsigned long long result = 0;
    for (size_t i = 0; i < digits.size(); i++)
        result = result * 10 + (digits[i] - '0');
    return result;
}

std::ostream& operator<<(std::ostream& os, const bigint& b)
{
    return os << b.digits;
}