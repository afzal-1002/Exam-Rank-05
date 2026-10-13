/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:50:48 by faikhan           #+#    #+#             */
/*   Updated: 2026/02/22 23:59:42 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

class bigint {
    private:
        std::string _value;
        
    public:
        bigint();
        bigint(unsigned int n);
        bigint(const bigint& copy);
        bigint& operator=(const bigint& other);
       
        std::string getValue() const;

        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);

        bigint& operator++();
        bigint operator++(int);
        
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
        bool operator<(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>=(const bigint& other) const;

        bigint operator<<(unsigned int n) const;
        bigint operator>>(unsigned int n) const;
        bigint& operator<<=(unsigned int n);
        bigint& operator>>=(unsigned int n);

        bigint operator<<(const bigint& other) const;
        bigint operator>>(const bigint& other) const;
        bigint& operator<<=(const bigint& other);
        bigint& operator>>=(const bigint& other);

        friend std::ostream& operator<<(std::ostream& os, const bigint& obj);
           
        ~bigint();
};