
#include "bigint.hpp"

bigint::bigint(): _value("0") {}

bigint::bigint(unsigned int num) {
    std::stringstream input;
    input << num;
    _value = input.str();
    //std::cout << _value << std::endl;
}

bigint::bigint(const bigint& copy) {
    *this = copy;
}

std::string bigint::getValue() const {
    std::cout << _value << std::endl;
    return (_value);
}

bigint& bigint::operator=(const bigint& other) {
    if(this != &other)
        _value = other._value;
    return (*this);
}

unsigned int strtouint(std::string str)
{
    std::stringstream ss;
    unsigned int ret;
    ss << str;
    ss >> ret;
    return (ret);
}
bigint bigint::operator+(const bigint& other) const {
    int i = static_cast<int> (this->_value.size()) - 1;
    int j = static_cast<int> (other._value.size()) - 1;
    std::string result;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry)
    {
        int x = 0;
        if(i >= 0) {
            x = _value[i] - '0';
            --i;
        }
        int y = 0;
        if(j >= 0) {
            y = other._value[j] - '0';
            --j;
        }
        int sum = x + y + carry;
        carry = sum / 10;
        result.push_back((sum%10) + '0');
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
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int) {
    bigint temp = *this;
    *this += bigint(1);
    return(temp);
}

bool bigint::operator==(const bigint& other) const {
    return (_value == other._value);
}

bool bigint::operator!=(const bigint& other) const {
    return (!(_value == other._value));
}

bool bigint::operator<(const bigint& other) const {
    if(_value.length() != other._value.length())
        return(_value.length() < other._value.length());
    return (_value < other._value);
}

bool bigint::operator>(const bigint& other) const {
    return (other < *this);
}

bool bigint::operator<=(const bigint& other) const {
    return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}

bigint bigint::operator<<(unsigned int k) const {
    bigint temp = *this;
    temp._value.insert(temp._value.end(), k, '0');
    return (temp);
}

bigint bigint::operator>>(unsigned int k) const {
    bigint temp = *this;
    size_t len = temp._value.length();
    if( k >= len)
        temp._value = "0";
    else
        temp._value.erase(len - k, k);
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
    temp = temp << strtouint(other._value);
    return (temp);
}

bigint bigint::operator>>(const bigint& other) const {
    bigint temp = *this;
    temp = temp >> strtouint(other._value);
    return (temp);
}

bigint& bigint::operator<<=(const bigint& other) {
    *this = *this << strtouint(other._value);
    return (*this);
}

bigint& bigint::operator>>=(const bigint& other) {
    *this = *this >> strtouint(other._value);
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const bigint& obj) {
    os << obj.getValue();
    return os;
}