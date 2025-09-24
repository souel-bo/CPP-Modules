/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 03:21:01 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/24 05:59:15 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private :
        int fixed;
        static const int bits = 8;
    public :
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &others);
        ~Fixed();
        int getRawBits();
        float toFloat(void) const;
        int toInt(void) const;
        void setRawBits( int const raw );
};
std::ostream &operator<<(std::ostream &out, const Fixed &f);
#endif