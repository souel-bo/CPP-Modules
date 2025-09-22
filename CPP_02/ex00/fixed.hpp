/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 03:21:01 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/22 04:33:36 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private :
        int fixed;
        static const int bits;
    public :
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &others);
        ~Fixed();
        int getRawBits();
        void setRawBits( int const raw );
};

#endif