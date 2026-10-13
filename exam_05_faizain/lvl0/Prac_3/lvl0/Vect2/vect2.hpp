/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:24:08 by faikhan           #+#    #+#             */
/*   Updated: 2026/03/31 02:50:41 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

 #include <iostream>

class vect2{
    private:
        int _x;
        int _y;

    public:
        vect2();
        vect2(int a, int b);
        vect2(const vect2& copy);
		vect2& operator=(const vect2& copy);
        ~vect2();
		
		vect2 operator+(const vect2& other) const;
		vect2 operator-(const vect2& other) const;
		vect2 operator*(const int scalar) const;

		vect2 operator+=(const vect2& other);
		vect2 operator-=(const vect2& other);
		vect2 operator*=(const int scalar);
		
		vect2 operator-() const;
		vect2 operator+() const;

		vect2& operator++();
		vect2& operator--();
		vect2 operator++(int);
		vect2 operator--(int);

		bool operator==(const vect2& other) const;
		bool operator!=(const vect2& other) const;

		int& operator[](int i);
		const int& operator[](int i) const;
};

std::ostream& operator<<(std::ostream& os, const vect2& obj);
vect2 operator*(const int scalar, const vect2& obj);

#endif