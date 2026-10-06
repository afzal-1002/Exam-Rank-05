#include "bigint.hpp"

bigint::bigint() : digits("0") {}

bigint::bigint(unsigned long long num)
{
    if(num == 0)
        digits = "0";
    else
    {
        while(num > 0)
        {
            digits = char(num % 10 + '0') + digits;
            num /= 10;
        }
    }
}

bigint::bigint(const bigint& other) : digits(other.digits) {}

bigint::~bigint() {}

bigint& bigint::operator=(const bigint& other)
{
    if(this != &other)
    {
        digits = other.digits;
    }
    return *this;
}

bigint bigint::operator+(const bigint& other) const
{
    bigint result;
    result.digits = "";
    int carry = 0;
    int i = digits.length() - 1;
    int j = other.digits.length() - 1;

    while((i >= 0) || (j >= 0) || carry)
    {
        int sum = carry;
        if(i >= 0)
        {
            sum += digits[i] - '0';
            i--;
        }
        if (j >=0)
        {
            sum += other.digits[j] - '0';
            j--;
        }
        result.digits = char('0' + (sum % 10)) + result.digits;
        carry = sum / 10;
    }
    return result;
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
    bigint temp = *this;
    ++(*this);
    return temp;
}

bigint bigint::operator<<(unsigned int shift) const
{
    bigint result;

    if(digits == "0")
        return *this;

    result = *this;
    unsigned long int i = 0;
    while (i < shift)
    {
        result.digits += '0';
        i++;
    }
    return result;
    
}

bigint bigint::operator>>(const bigint& shift) const
{
    bigint result;  
    unsigned long long sh = shift.ullong();

    if(sh > digits.length())
    {
        result.digits = "0";
        return result;
    }
    result.digits = digits.substr(0, digits.length()- sh);
    if(result.digits.empty())
        result.digits = "0";
    return result;
}

bigint& bigint::operator<<=(unsigned int shift)
{
    *this = *this << shift;
    return *this;
}

        /* code */
bigint& bigint::operator>>=(const bigint& shift)
{
    *this = *this >> shift;
    return *this;
}

bool bigint::operator<(const bigint& other) const
{
    if(digits.length() != other.digits.length())
        return digits.length() < other.digits.length();
    else   
        return digits < other.digits;
}

bool bigint::operator<=(const bigint& other) const
{
    if(*this < other || *this == other)
        return true;
    return false; 
}

bool bigint::operator>(const bigint& other) const
{
    if(*this <= other)
        return false;
    return true;
}

bool bigint::operator>=(const bigint& other) const
{
    if(*this < other)
        return false;
    return true;
}

bool bigint::operator==(const bigint& other) const
{
    if(digits == other.digits)
        return true;
    return false;
}

bool bigint::operator!=(const bigint& other )const
{
    if(digits != other.digits)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& os, const bigint& num)
{
    os << num.digits;
    return os;
}

unsigned long long bigint::ullong() const
{
    unsigned long long result = 0;
    unsigned int i = 0;
    while(i < digits.length())
    {
        result = result * 10 + digits[i] - '0';
        i++;
    }
    return result;
}