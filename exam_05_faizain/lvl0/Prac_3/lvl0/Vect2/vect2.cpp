/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:24:05 by faikhan           #+#    #+#             */
/*   Updated: 2026/04/01 21:39:44 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}

vect2::vect2(int a, int b) : _x(a), _y(b) {}

vect2::vect2(const vect2& copy) {
	*this = copy;
}

vect2::~vect2() {}

vect2& vect2::operator=(const vect2& copy) {
	if(this != &copy)
	{
		_x = copy._x;
		_y = copy._y;
	}
	return (*this);
}

vect2 vect2::operator+(const vect2& other) const {
	int a = _x + other._x;
	int b = _y + other._y;
	return (vect2(a, b));
}

vect2 vect2::operator-(const vect2& other) const {
	int a = _x - other._x;
	int b = _y - other._y;
	return (vect2(a, b));
}

vect2 vect2::operator*(const int scalar) const {
	int a = _x * scalar;
	int b = _y * scalar;
	return (vect2(a, b));
}

vect2 vect2::operator+=(const vect2& other) {
	*this = *this + other;
	return (*this);
}

vect2 vect2::operator-=(const vect2& other) {
	*this = *this - other;
	return (*this);
}

vect2 vect2::operator*=(const int scalar) {
	*this = *this * scalar;
	return (*this);
}

vect2 vect2::operator+() const {
	vect2 temp = *this;
	return (temp);
}

vect2 vect2::operator-() const {
	return (vect2(-_x, -_y));
}

vect2& vect2::operator++() {
	++_x;
	++_y;
	return (*this);
}

vect2& vect2::operator--() {
	--_x;
	--_y;
	return (*this);
}

vect2 vect2::operator++(int) {
	vect2 temp = *this;
	++_x;
	++_y;
	return (temp);
}

vect2 vect2::operator--(int) {
	vect2 temp = *this;
	--_x;
	--_y;
	return (temp);
}

bool vect2::operator==(const vect2& other) const {
	return ((_x == other._x) && (_y == other._y));
}

bool vect2::operator!=(const vect2& other) const{
	return (!((_x == other._x) && (_y == other._y)));
}
int& vect2::operator[](int i) {
	if(i == 0)
		return(_x);
	else
		return (_y);
}

const int& vect2::operator[](int i) const {
	if(i == 0)
		return (_x);
	else
		return (_y);
}

std::ostream& operator<<(std::ostream& os, const vect2& obj) {
	os << "{" << obj[0] << ", " << obj[1] << "}";
	return (os);
}

vect2 operator*(const int scalar, const vect2& obj) {
	return (obj * scalar);
}