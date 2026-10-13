#include "bigint.hpp"
#include <sstream>
#include <algorithm>

// ---------- Private Helpers ----------

std::string bigint::normalize(const std::string& str)
{
    size_t first = str.find_first_not_of('0');
    if (first == std::string::npos)
        return "0";
    return str.substr(first);
}

static unsigned int toUnsigned(const std::string& str)
{
    std::stringstream ss(str);
    unsigned int n = 0;
    ss >> n;
    return n;
}

std::string bigint::addStrings(const std::string& a, const std::string& b)
{
    std::string result;
    int carry = 0;

    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

// ---------- Constructors ----------

bigint::bigint() : _value("0") {}

bigint::bigint(unsigned int n)
{
    std::stringstream ss;
    ss << n;
    _value = ss.str();
}

bigint::bigint(const std::string& str)
{
    _value = normalize(str);
}

bigint::bigint(const bigint& other) : _value(other._value) {}

// ---------- Assignment ----------

bigint& bigint::operator=(const bigint& other)
{
    if (this != &other)
        _value = other._value;
    return *this;
}

// ---------- Getter ----------

std::string bigint::getValue() const
{
    return _value;
}

// ---------- Arithmetic ----------

bigint bigint::operator+(const bigint& other) const
{
    return bigint(addStrings(_value, other._value));
}

bigint& bigint::operator+=(const bigint& other)
{
    *this = *this + other;
    return *this;
}

bigint& bigint::operator++()
{
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint temp(*this);
    ++(*this);
    return temp;
}

// ---------- Comparisons ----------

bool bigint::operator==(const bigint& other) const
{
    return _value == other._value;
}

bool bigint::operator!=(const bigint& other) const
{
    return !(*this == other);
}

bool bigint::operator<(const bigint& other) const
{
    if (_value.length() != other._value.length())
        return _value.length() < other._value.length();

    return _value < other._value;
}

bool bigint::operator>(const bigint& other) const
{
    return other < *this;
}

bool bigint::operator<=(const bigint& other) const
{
    return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const
{
    return !(*this < other);
}

// ---------- Decimal Shift ----------

bigint bigint::operator<<(unsigned int n) const
{
    if (_value == "0")
        return *this;

    return bigint(_value + std::string(n, '0'));
}

bigint bigint::operator>>(unsigned int n) const
{
    if (n >= _value.length())
        return bigint("0");

    return bigint(_value.substr(0, _value.length() - n));
}

bigint& bigint::operator<<=(unsigned int n)
{
    *this = *this << n;
    return *this;
}

bigint& bigint::operator>>=(unsigned int n)
{
    *this = *this >> n;
    return *this;
}

bigint bigint::operator<<(const bigint& other) const
{
    return *this << toUnsigned(other.getValue());
}

bigint bigint::operator>>(const bigint& other) const
{
    return *this >> toUnsigned(other.getValue());
}

bigint& bigint::operator<<=(const bigint& other)
{
    *this = *this << other;
    return *this;
}

bigint& bigint::operator>>=(const bigint& other)
{
    *this = *this >> other;
    return *this;
}
// ---------- Stream ----------

std::ostream& operator<<(std::ostream& os, const bigint& obj)
{
    os << obj._value;
    return os;
}
