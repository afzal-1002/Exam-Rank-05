#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

class bigint {
private:
    std::vector<int> digits; // digits[0] is the most significant digit

    void trim(); // remove leading zeros

public:
    // Constructors
    bigint();                 // default 0
    bigint(unsigned int n);   // from unsigned int
    bigint(const bigint& other); // copy constructor

    // Accessor for printing
    std::string toString() const;

    // Assignment
    bigint& operator=(const bigint& other);

    // Addition
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);

    // Increment
    bigint& operator++();      // prefix ++
    bigint operator++(int);    // postfix ++

    // Digit shifts
    bigint operator<<(unsigned int n) const;
    bigint operator>>(unsigned int n) const;
    bigint& operator<<=(unsigned int n);
    bigint& operator>>=(unsigned int n);

    // Comparisons
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;

    // Friend for printing
    friend std::ostream& operator<<(std::ostream& os, const bigint& n);
};
