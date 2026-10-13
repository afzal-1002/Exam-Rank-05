#ifndef BIGINT_HPP
#define BIGINT_HPP
#include<iostream>
#include<sstream>
#include<algorithm>

class bigint {
    private:
        std::string _value;
    public:
        bigint();
        bigint(unsigned int num);
        bigint(const bigint& copy);
        // ~bigint();

        std::string getValue() const;
        bigint& operator=(const bigint& other);

        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);

        bigint& operator++();
        bigint operator++(int);

        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
        bool operator<(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>=(const bigint& other) const;

        bigint operator<<(unsigned int k) const;
        bigint operator>>(unsigned int k) const;
        bigint& operator<<=(unsigned int k);
        bigint& operator>>=(unsigned int k);

        bigint operator<<(const bigint& other) const;
        bigint operator>>(const bigint& other) const;
        bigint& operator<<=(const bigint& other);
        bigint& operator>>=(const bigint& other);
};

std::ostream& operator<<(std::ostream& os, const bigint& obj);

#endif