#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint
{
private:
    std::string _value;

    static std::string normalize(const std::string& str);
    static std::string addStrings(const std::string& a, const std::string& b);

public:
    // Constructors
    bigint();
    bigint(unsigned int n);
    bigint(const std::string& str);
    bigint(const bigint& other);

    // Assignment
    bigint& operator=(const bigint& other);

    // Getter
    std::string getValue() const;

    // Arithmetic
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);

    bigint& operator++();     // prefix
    bigint operator++(int);   // postfix

    // Comparisons
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;

    // Decimal shift (×10ⁿ and ÷10ⁿ)
    bigint operator<<(unsigned int n) const;
    bigint operator>>(unsigned int n) const;
    bigint& operator<<=(unsigned int n);
    bigint& operator>>=(unsigned int n);
    
    bigint operator<<(const bigint& other) const;
    bigint operator>>(const bigint& other) const;
    bigint& operator<<=(const bigint& other);
    bigint& operator>>=(const bigint& other);
    // Stream output
    friend std::ostream& operator<<(std::ostream& os, const bigint& obj);
};

#endif
