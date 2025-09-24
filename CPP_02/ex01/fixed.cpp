/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 04:06:16 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/24 05:59:09 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"


std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();  
    return out;
}


int Fixed::toInt(void) const
{
    return fixed >> 8;
}

float Fixed::toFloat(void) const
{
    return (float)fixed / (1 << 8);
}

Fixed::Fixed(const float value)
{
    this->fixed = roundf(value * (1 << bits));
    std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const int value)
{
    this->fixed = value << bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fixed = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed = other.fixed;
}

Fixed& Fixed::operator=(const Fixed &others)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &others)
        this->fixed = others.fixed;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits()
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed;
}
void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits  member function called" << std::endl;
    fixed = raw;
}