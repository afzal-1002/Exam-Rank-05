#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <algorithm>
#include <sstream>

class bigint {
    private:
        std::string _value;
    
    public:
        bigint();
        bigint(const std::string& str );
        bigint(unsigned int num);
        bigint(const bigint& copy);
        ~bigint();
        
        std::string getValue() const;
        bigint& operator=(const bigint& other);

        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);

        bigint& operator++();
        bigint operator++(int);

        bigint operator<<(unsigned int n) const;
        bigint operator>>(unsigned int n) const;
        bigint& operator<<=(unsigned int n);
        bigint& operator>>=(unsigned int n);


        bigint operator<<(const bigint& other) const;
        bigint& operator<<=(const bigint& other);
        bigint operator>>(const bigint& other) const;
        bigint& operator>>=(const bigint& other);

        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
        bool operator<(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>=(const bigint& other) const;
};

std::ostream& operator<<(std::ostream& os, const bigint& other);
#endif 