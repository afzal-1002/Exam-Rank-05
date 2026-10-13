#include "bigint.hpp"

bigint::bigint() : _value("0") {};

bigint::bigint(unsigned int n) {
    std::stringstream input;
    input << n;
    _value = input.str();
    //std::cout << _value << std::endl;
}

bigint::bigint(const bigint& copy) {
   std::cout << "copy const called" << std::endl;
    *this = copy;
}

bigint& bigint::operator=(const bigint& other) {
    if(this != &other)
        _value = other._value;
    return (*this);
}

std::string bigint::getValue() const {
     std::cout << this->_value << std::endl;
    return (_value);
}

bigint bigint::operator+(const bigint& other) const {
    int carry = 0;
    int i = static_cast<int>(this->_value.length() - 1);
    int j = static_cast<int>(other._value.length() - 1);
    std::string result;
    while( i >= 0 || j >= 0 || carry)
    {
        int x = 0;
        if(i >= 0)
        {
            x = this->_value[i] - '0';
            --i;
        }
        int y = 0;
        if(j >= 0)
        {
            y = other._value[i] - '0';
            --j;
        }
        int sum = x + y + carry;
        carry = sum / 10;
        result.push_back(((sum % 10) + '0'));
    }
    std::reverse(result.begin(), result.end());
    bigint temp;
    temp._value = result;
    return (temp);
}

bigint& bigint::operator+=(const bigint& other) {
    *this = *this + other;
    return (*this);
}

bigint& bigint::operator++() {
    *this = *this + bigint(1);
    return (*this);
}

bigint bigint::operator++(int) {
    bigint temp = *this;
    *this = ++(*this);
    return (temp);
}

bool bigint::operator==(const bigint& other) const {
    return (this->_value == other._value);
}


bool bigint::operator!=(const bigint& other) const {
    return (!(this->_value == other._value));
}

bool bigint::operator<(const bigint& other) const {
    if(this->_value.length() != other._value.length())
        return (_value.length() < other._value.length());
    return (_value < other._value);
}

bool bigint::operator>(const bigint& other) const {
    return (!(*this < other));
}

bool bigint::operator<=(const bigint& other) const {
    return (!(*this > other));
}

bool bigint::operator>=(const bigint& other) const {
    return (!(*this < other));
}

bigint bigint::operator<<(unsigned int k) const {
    bigint temp = *this;
    temp._value.insert(temp._value.end(), k, '0');
    return(temp);
}

bigint bigint::operator>>(unsigned int k) const {
    bigint temp = *this;
    size_t len = temp._value.length();
    if (k >= len)
        temp._value = "0";
    else
        temp._value.erase(len-k, k);
    return (temp);
}

bigint& bigint::operator<<=(unsigned int k) {
    *this = *this << k;
    return (*this);
}


bigint& bigint::operator>>=(unsigned int k) {
    *this = *this >> k;
    return (*this);
}

bigint bigint::operator<<(const bigint& other) const {
    bigint temp = *this;
    temp = *this << std::stoi(other._value);
    return (temp);
}


bigint bigint::operator>>(const bigint& other) const {
    bigint temp = *this;
    temp = *this >> std::stoi(other._value);
    return (temp);
}


bigint& bigint::operator<<=(const bigint& other) {
    *this = *this << std::stoi(other._value);
    return (*this);
}

bigint& bigint::operator>>=(const bigint& other) {
    *this = *this >> std::stoi(other._value);
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const bigint& obj) {
    os << obj._value;
    return (os);
}

bigint::~bigint() {};