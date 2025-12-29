/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:10:52 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/29 17:48:32 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& other){
    (void)other;
}
ScalarConverter&::ScalarConverter:: operator=(const ScalarConverter& other){
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter(){}

void::ScalarConverter::convert(const std::string &literal){
    if (literal.length() == 1 && !isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }
    char* end;
    double value = strtod(literal.c_str(), &end);
    if (end == literal.c_str() || (*end != '\0' && *end != 'f')) {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : impossible" << std::endl;
        std::cout << "double : impossible" << std::endl;
        return;
    }
    
}