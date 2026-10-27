#include "vect2.hpp"

vect2::vect2()
{
    this->x = 0;
    this->y = 0;
}

vect2::vect2(int a, int b)
{
    this->x = a;
    this->y = b;
}

vect2::vect2(const vect2& other)
{
    this->x = other.x;
    this->y = other.y;
}

vect2& vect2::operator=(const vect2& other)
{
    if( this != &other)
    {
        this->x = other.x;
        this->y = other.y;
    } 
    return *this;
}

vect2::~vect2()
{
    // nothing to do
}

vect2 vect2::operator+(const vect2& other) const
{
    return vect2(*this) += other ;
}

vect2 vect2::operator-(const vect2& other) const
{
    return vect2(*this) -= other ;
}

vect2 vect2::operator*(int s) const
{
    return vect2(*this) *= s ;
}

vect2& vect2::operator+=(const vect2& other)
{
    this->x += other.x;
    this->y += other.y;
    return *this ;
}

vect2& vect2::operator-=(const vect2& other)
{
    this->x -= other.x;
    this->y -= other.y;
    return *this ;
}

vect2& vect2::operator*=(int s)
{
    this->x *= s;
    this->y *= s;
    return *this ;
}

vect2 vect2::operator+() const
{
    return vect2(*this);
}

vect2 vect2::operator-() const
{
    return vect2(-this->x, -this->y);
}

vect2& vect2::operator++()
{
    ++this->x;
    ++this->y;
    return *this;
}

vect2& vect2::operator--()
{
    --this->x;
    --this->y;
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 temp(*this);
    ++(*this);
    return temp;
}

vect2 vect2::operator--(int)
{
    vect2 temp(*this);
    --(*this);
    return temp;
}

bool vect2::operator==(const vect2& other) const
{
    return (this->x == other.x) && (this->y == other.y);
}

bool vect2::operator!=(const vect2& other) const
{
    return (this->x != other.x) || (this->y != other.y);
}

int& vect2::operator[] (int i)
{
    return (i == 0) ? this->x : this->y;
}

const int& vect2::operator[] (int i) const
{
    return (i == 0) ? this->x : this->y;
}

std::ostream& operator<<(std::ostream& os, const vect2& v)
{
    return os << "{" << v.x << ", " << v.y << "}";
}

vect2 operator*(int s, const vect2& v)
{
    return v * s;
}
