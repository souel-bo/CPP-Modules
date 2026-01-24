/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:24:14 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/24 18:51:21 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return 1;
    }
    if (argv[1][0] == '\0')
    {
        std::cerr << "Error: Empty expression." << std::endl;
        return 1;
    }
    try {
        RPN rpnCalculator;
        std::string str(argv[1]);
        if (str.size() < 3)
            throw std::runtime_error("Error");
        rpnCalculator.evaluate(argv[1]);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}