/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:16:04 by faikhan           #+#    #+#             */
/*   Updated: 2026/02/23 00:10:16 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

bigint::bigint() : _value("0") {};

bigint::bigint(unsigned int n) {
    std::stringstream input_number;
    input_number << n;
    _value = input_number.str();
    std::cout << "Testing the store value : " << _value << std::endl;
}

bigint::bigint(const bigint& copy) {
    *this = copy;
}

bigint& bigint::operator=(const bigint& other) {
    if (this != &other)
        _value = other._value;
    return *this;
}

std::string bigint::getValue() const {
    return _value;
}

bigint bigint::operator+(const bigint &other) const
{
    int carry = 0;
    int i = static_cast<int>(_value.size()) - 1;
    int j = static_cast<int>(other._value.size()) - 1;
    std::string result;

    while (i >= 0 || j >= 0 || carry)
    {
        int x = 0;
        if (i >= 0) {
            x = _value[i] - '0';
            --i;
        }
        
        int y = 0;
        if (j >= 0) {
            y = other._value[j] - '0';
            --j;   
        }
        int sum = x + y + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    std::reverse(result.begin(), result.end());
    bigint temp;
    temp._value = result;
    return temp;
}

bigint& bigint::operator+=(const bigint& other) {
    *this = *this + other;
    return *this;
}

bigint& bigint::operator++() {
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int) {
    bigint temp(*this);
    ++(*this);
    return temp;
}

bool bigint::operator==(const bigint& other) const {
    return (_value == other._value);
}

bool bigint::operator!=(const bigint& other) const {
    return (!(*this == other));
}

bool bigint::operator<(const bigint& other) const {
    if (_value.length() != other._value.length())
        return (_value.length() < other._value.length());
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

bigint bigint::operator<<(unsigned int n) const {
    bigint temp = *this;
    temp._value.insert(temp._value.end(), n, '0');
    return(temp);
}

bigint bigint::operator>>(unsigned int n) const {
    bigint temp = *this;
    size_t len = temp._value.length();
    if (n >= len)
        temp._value = "0";
    else
        temp._value.erase(len - n, n);
    return (temp);
}

bigint& bigint::operator<<=(unsigned int n) {
    *this = *this << n;
    return (*this);
}

bigint& bigint::operator>>=(unsigned int n) {
    *this = *this >> n;
    return (*this);
}

bigint bigint::operator<<(const bigint& other) const {
      bigint temp;
      temp = *this << std::stoi(other._value);
      return (temp); 
}

bigint bigint::operator>>(const bigint& other) const {
    bigint temp;
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
