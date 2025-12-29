/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:10:52 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/29 18:43:52 by souel-bo         ###   ########.fr       */
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

void print_char(double value){
    if (value < 0 || value > 127 || isnan(value) || isinf(value)) {
        std::cout << "char: impossible" << std::endl;
    } else if (!isprint(static_cast<char>(value))) {
        std::cout << "char: non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
}
void print_int( double value){
    if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX) || isnan(value) || isinf(value)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}
void print_float(double value){
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
}
void print_double(double value){
    std::cout << "double: " << static_cast<double>(value) << std::endl;        
}

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
    if (std::string(end) == "f" && end == literal.c_str() + literal.length() - 1) {} 
    else if (*end != '\0') {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : impossible" << std::endl;
        std::cout << "double : impossible" << std::endl;
        return;
    }
    print_char(value);
    print_int(value);
    print_float(value);
    print_double(value);
}