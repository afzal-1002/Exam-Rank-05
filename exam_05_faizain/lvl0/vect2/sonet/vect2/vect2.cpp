#include "vect2.hpp"

// --- CONSTRUCTORS ---

// Default constructor: creates a vector (0, 0)
vect2::vect2() : x(0), y(0) {}

// Constructor with two values: creates a vector (a, b)
vect2::vect2(int a, int b) : x(a), y(b) {}

// Copy constructor: creates a copy of another vector
vect2::vect2(const vect2 &other) : x(other.x), y(other.y) {}


// --- ARRAY ACCESS OPERATOR [] ---
// v[0] returns x, v[1] returns y
// Two versions: one for normal vectors (read+write), one for const vectors (read only)

int &vect2::operator[](int index)
{
    if (index == 0) return x;
    return y;
}

const int &vect2::operator[](int index) const
{
    if (index == 0) return x;
    return y;
}


// --- ASSIGNMENT OPERATORS ---
// These modify the current vector in place and return *this so calls can be chained

vect2 &vect2::operator=(const vect2 &other)
{
    x = other.x;
    y = other.y;
    return *this;
}

vect2 &vect2::operator+=(const vect2 &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

vect2 &vect2::operator-=(const vect2 &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

vect2 &vect2::operator*=(int scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}


// --- INCREMENT / DECREMENT ---
// ++ and -- affect BOTH components by 1

// Prefix ++v: increment first, then return the updated vector
vect2 &vect2::operator++()
{
    x++;
    y++;
    return *this;
}

// Postfix v++: save old value, increment, return old value
// The dummy (int) parameter is just how C++ distinguishes postfix from prefix
vect2 vect2::operator++(int)
{
    vect2 old = *this;
    x++;
    y++;
    return old;
}

// Prefix --v
vect2 &vect2::operator--()
{
    x--;
    y--;
    return *this;
}

// Postfix v--
vect2 vect2::operator--(int)
{
    vect2 old = *this;
    x--;
    y--;
    return old;
}


// --- UNARY MINUS ---
// -v returns a new vector with both components negated
vect2 vect2::operator-() const
{
    return vect2(-x, -y);
}


// --- COMPARISON ---

bool vect2::operator==(const vect2 &other) const
{
    return (x == other.x && y == other.y);
}

bool vect2::operator!=(const vect2 &other) const
{
    return !(*this == other); // reuse == to avoid duplicating logic
}


// --- NON-MEMBER OPERATORS ---
// These live outside the class because the left-hand side isn't always a vect2

// v1 + v2: takes 'left' by value (a copy), modifies and returns it
vect2 operator+(vect2 left, const vect2 &right)
{
    left += right;
    return left;
}

// v1 - v2
vect2 operator-(vect2 left, const vect2 &right)
{
    left -= right;
    return left;
}

// v * 3
vect2 operator*(vect2 v, int scalar)
{
    v *= scalar;
    return v;
}

// 3 * v  (int on the left side — must be a non-member)
vect2 operator*(int scalar, vect2 v)
{
    v *= scalar;
    return v;
}

// std::cout << v  =>  prints "{x, y}"
std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
    os << "{" << v[0] << ", " << v[1] << "}";
    return os; // return the stream so << calls can be chained
}
