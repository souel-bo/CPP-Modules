/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:51:37 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/02 22:51:37 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>

#include "whatever.hpp"

int	main(void)
{
        int			a = 2;
        int			b = 3;
        std::string	c = "chaine1";
        std::string	d = "chaine5";

        ::swap(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
        std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
        return (0);
}
