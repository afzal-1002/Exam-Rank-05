#include "vect.hpp"

// Constructors, assignment, destructor
vect::vect() : x(0), y(0) {}
vect::vect(int a, int b) : x(a), y(b) {}
vect::vect(const vect& o) : x(o.x), y(o.y) {}
vect& vect::operator=(const vect& o) { x = o.x; y = o.y; return *this; }
vect::~vect() {}

// Arithmetic (return a new vect)
vect vect::operator+(const vect& o) const { return vect(*this) += o; }
vect vect::operator-(const vect& o) const { return vect(*this) -= o; }
vect vect::operator*(int s) const         { return vect(*this) *= s; }

// Compound assignment (modify this vect)
vect& vect::operator+=(const vect& o) { x += o.x; y += o.y; return *this; }
vect& vect::operator-=(const vect& o) { x -= o.x; y -= o.y; return *this; }
vect& vect::operator*=(int s)         { x *= s;   y *= s;   return *this; }

// Unary
vect vect::operator+() const { return *this; }
vect vect::operator-() const { return vect(-x, -y); }

// Increment / decrement (prefix, then postfix)
vect& vect::operator++()    { ++x; ++y; return *this; }
vect& vect::operator--()    { --x; --y; return *this; }
vect  vect::operator++(int) { vect t(*this); ++*this; return t; }
vect  vect::operator--(int) { vect t(*this); --*this; return t; }

// Comparison
bool vect::operator==(const vect& o) const { return (x == o.x) && (y == o.y); }
bool vect::operator!=(const vect& o) const { return !((x == o.x) && (y == o.y));}

// Access: v[0] is x, v[1] is y
int&       vect::operator[](int i)       { return i ? y : x; }
const int& vect::operator[](int i) const { return i ? y : x; }

// Free functions
vect operator*(int s, const vect& v) { return v * s; }

std::ostream& operator<<(std::ostream& os, const vect& v)
{
    return os << "{" << v[0] << ", " << v[1] << "}";
}