#pragma once
#include <iostream>

class vect2
{
public:
    int x;
    int y;

    // Constructors
    vect2();
    vect2(int a, int b);
    vect2(const vect2 &other);

    // Array access
    int       &operator[](int index);
    const int &operator[](int index) const;

    // Assignment operators
    vect2 &operator=(const vect2 &other);
    vect2 &operator+=(const vect2 &other);
    vect2 &operator-=(const vect2 &other);
    vect2 &operator*=(int scalar);

    // Increment / Decrement
    vect2 &operator++();    // prefix  ++v
    vect2  operator++(int); // postfix v++
    vect2 &operator--();    // prefix  --v
    vect2  operator--(int); // postfix v--

    // Unary minus
    vect2 operator-() const;

    // Comparison
    bool operator==(const vect2 &other) const;
    bool operator!=(const vect2 &other) const;
};

// Non-member operators (declared outside the class)
vect2         operator+(vect2 left, const vect2 &right);
vect2         operator-(vect2 left, const vect2 &right);
vect2         operator*(vect2 v, int scalar);
vect2         operator*(int scalar, vect2 v);
std::ostream &operator<<(std::ostream &os, const vect2 &v);
