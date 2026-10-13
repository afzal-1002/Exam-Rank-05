#include "vect2.hpp"

vect2::vect2(): x(0), y(0) {};

vect2::vect2(int a, int b): x(a), y(b) {};

vect2::vect2(const vect2& copy) {
    *this = copy;
}

vect2::~vect2() {};

vect2& vect2::operator=(const vect2& other) {
    if(this != &other)
    {
        this->x = other.x;
        this->y = other.y;
    }
    return (*this);
}

vect2 vect2::operator+(const vect2& other) const {
    int a = x + other.x;
    int b = y + other.y;
    return (vect2(a, b));
}

vect2 vect2::operator-(const vect2& other) const {
    int a = x - other.x;
    int b = y - other.y;
    return (vect2(a, b));
}

vect2 vect2::operator*(const int scalar) const {
    int a = x * scalar;
    int b = y * scalar;
    return (vect2(a, b));
}

vect2& vect2::operator+=(const vect2& other) {
    *this = *this + other;
    return(*this);
}

vect2& vect2::operator-=(const vect2& other) {
    *this = *this - other;
    return *this;
}

vect2& vect2::operator*=(const int scalar) {
    *this = *this * scalar;
    return *this;
}

vect2 vect2::operator+() const {
    vect2 temp = *this;
    return (temp);
}
vect2 vect2::operator-() const {
    return (vect2(-x, -y));
}

vect2& vect2::operator++() {
    ++x;
    ++y;
    return (*this);
}

vect2 vect2::operator++(int) {
    vect2 temp;
    temp = *this;
    ++x;
    ++y;
    return (temp);
}


vect2& vect2::operator--() {
    --x;
    --y;
    return (*this);
}

vect2 vect2::operator--(int) {
    vect2 temp;
    temp = *this;
    --x;
    --y;
    return (temp);
}

bool vect2::operator==(const vect2& other) const {
    return ((x==other.x) && (y == other.y));
}


bool vect2::operator!=(const vect2& other) const {
    return !((x==other.x) && (y == other.y));
}

int& vect2::operator[](int i) {
    if(i == 0)
        return (x);
    else
        return (y);
}

const int& vect2::operator[](int i) const {
    if(i == 0)
        return (x);
    else
        return (y);
}

std::ostream& operator<<(std::ostream& os, const vect2& other) 
{
    os << "{" << other[0] << ", " << other[1] << "}";
    return (os);
}

vect2 operator*(const int scalar, const vect2& other) {
    return (other * scalar);
}