#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>

class bigint
{
    private:    
        std::string digits;
    
    public:
        bigint();
        bigint(unsigned long long num);
        bigint(const bigint& other);
        bigint& operator=(const bigint& other);
        ~bigint();

        bigint operator+(const bigint& other) const;
        bigint operator++(int);
        bigint& operator++();
        bigint& operator+=(const bigint& other);

        bigint operator<<(unsigned int shift) const;
        bigint operator>>(const bigint& shift) const;

        bigint& operator<<=(unsigned int shift);
        bigint& operator>>=(const bigint& shift);

        bool operator<(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        bool operator==(const bigint& other)const;
        bool operator!=(const bigint& other) const;

        friend std::ostream& operator<<(std::ostream& os, const bigint& num);

        unsigned long long ullong() const;

};

#endif