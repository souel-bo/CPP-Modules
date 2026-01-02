/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:51:17 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/02 23:03:04 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    Array<int> intArray(5);
    for (size_t i = 0; i < intArray.getSize(); ++i) {
        intArray[i] = i * 10;
    }
    for (size_t i = 0; i < intArray.getSize(); ++i) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";
    for (size_t i = 0; i < strArray.getSize(); ++i) {
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
    }

    try {
        std::cout << intArray[10] << std::endl;
    } catch (const std::out_of_range &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}