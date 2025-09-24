/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 04:06:16 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/24 23:17:09 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    else
        return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    else
        return b;
}


Fixed &Fixed::operator++() {
    this->fixed += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this); 
    this->fixed += 1;
    return temp; 
}

Fixed &Fixed::operator--() {
    this->fixed -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this); 
    this->fixed -= 1;
    return temp; 
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->fixed + other.fixed);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->fixed - other.fixed);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    long temp = (long)this->fixed * (long)other.fixed;
    result.setRawBits(temp >> bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    long temp = ((long)this->fixed << bits) / other.fixed;
    result.setRawBits(temp);
    return result;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->fixed > other.fixed;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->fixed < other.fixed;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->fixed >= other.fixed;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->fixed <= other.fixed;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->fixed == other.fixed;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->fixed != other.fixed;
}

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
    // std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const int value)
{
    this->fixed = value << bits;
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    fixed = 0;
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->fixed = other.fixed;
}

Fixed& Fixed::operator=(const Fixed &others)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &others)
        this->fixed = others.fixed;
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits()
{
    // std::cout << "getRawBits member function called" << std::endl;
    return fixed;
}
void Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits  member function called" << std::endl;
    fixed = raw;
}
