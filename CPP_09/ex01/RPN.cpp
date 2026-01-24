/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:24:56 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/24 18:38:25 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other){
    this->numbers = other.numbers;
}

RPN &RPN::operator=(const RPN &other){
    if (this != &other)
        this->numbers = other.numbers;
    return *this;
}

RPN::~RPN() {}

int RPN::is_operator(const std::string &token){
    return (token == "+" || token == "-" || token == "/" || token == "*");
}

void RPN::process_operation(const std::string &expression){
    if (numbers.size() < 2)
        throw std::runtime_error("Error");
     int b = numbers.top(); numbers.pop();
     int a = numbers.top(); numbers.pop();
     if (expression == "+"){
        numbers.push(a + b);
        // std::cout << a << " + " << b << std::endl;
     }
    else if (expression == "-"){
        numbers.push(a - b);
        // std::cout << a << " - " << b << std::endl;    
    }
    else if (expression == "*"){
        numbers.push(a * b);
        // std::cout << a << " * " << b << std::endl;
    }
    else if (expression == "/"){
        if (b == 0)
            throw std::runtime_error("Error");
        numbers.push(a / b);
        // std::cout << a << " / " << b << std::endl;
    }
}

void RPN::evaluate(std::string const &expression){
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token){
        if (is_operator(token))
            process_operation(token);
        else{
            if (token.size() != 1 || token[0] < '0' || token[0] > '9')
                throw std::runtime_error("Error");
            numbers.push(atoi(token.c_str()));
        }
    }
    if (numbers.size() != 1)
        throw std::runtime_error("Error");
    std::cout << numbers.top() << std::endl;
}