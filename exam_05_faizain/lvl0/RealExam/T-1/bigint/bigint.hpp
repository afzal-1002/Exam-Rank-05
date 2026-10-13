#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

class bigint {
    private:
        std::string _value;

    public:
        bigint();
        bigint(unsigned int n);
        bigint(const bigint& copy);
        ~bigint();
        
        bigint& operator=(const bigint& other);

        std::string getValue() const;

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
        
        friend std::ostream& operator<<( std::ostream& os, const bigint& obj);
};

#endif