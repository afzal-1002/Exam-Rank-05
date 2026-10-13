#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>

class bigint
{
    std::string digits;

public:
    bigint();                                   // default
    bigint(unsigned long long n);               // arg
    bigint(const std::string& s);               // arg (string)
    bigint(const bigint& o);                    // copy
    bigint& operator=(const bigint& o);         // assignment
    ~bigint();                                  // destructor

    bigint  operator+(const bigint& o) const;
    bigint& operator+=(const bigint& o);
    bigint& operator++();
    bigint  operator++(int);

    bigint  operator<<(const bigint& n) const;
    bigint  operator>>(const bigint& n) const;
    bigint& operator<<=(const bigint& n);
    bigint& operator>>=(const bigint& n);

    bool operator==(const bigint& o) const;
    bool operator!=(const bigint& o) const;
    bool operator<(const bigint& o) const;
    bool operator>(const bigint& o) const;
    bool operator<=(const bigint& o) const;
    bool operator>=(const bigint& o) const;

    unsigned long long toULL() const;

    friend std::ostream& operator<<(std::ostream& os, const bigint& b);
};

#endif