#ifndef VECT2_HPP
#define VECT2_HPP

#include<string>
#include <iostream>


class vect2
{

    private :
        int x;
        int y;

    public:
        vect2();
        vect2(int a, int b);
        vect2(const vect2& other);
        vect2& operator=(const vect2& other);
        ~vect2();

        vect2 operator+(const vect2& other)const;
        vect2 operator-(const vect2& other)const;
        vect2 operator*(int s)const;

        vect2& operator+=(const vect2& other);
        vect2& operator-=(const vect2& other);
        vect2& operator*=(int s);

        vect2 operator+() const;
        vect2 operator-() const;

        vect2& operator++();     // prefix
        vect2& operator--();
        vect2  operator++(int);  // postfix
        vect2  operator--(int);

        bool operator==(const vect2& other) const;
        bool operator!=(const vect2& other) const;

        int& operator[] (int i);
        const int& operator[] (int i) const;

        friend std::ostream& operator<<(std::ostream& os, const vect2& v);
};

        vect2 operator*(int s, const vect2& v);

    

#endif