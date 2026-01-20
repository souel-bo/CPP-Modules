/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:24:56 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/21 00:30:52 by souel-bo         ###   ########.fr       */
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

int RPN::evaluate(std::string const &expression){
    std::istringstream iss(expression);
    std::string token;
    int result;
    while (iss >> token){
        if (std::isdigit(token[0]) && token.length() == 1){
            numbers.push(atoi(token.c_str()));
        }
        else if (token.length() > 1 || !std::isdigit(token[0])){
            throw std::runtime_error("Error");
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/"){
            if (numbers.size() < 2)
                throw std::runtime_error("Error: Insufficient values in the expression.");

            int b = numbers.top(); numbers.pop();
            int a = numbers.top(); numbers.pop();

            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else {
                if (b == 0)
                    throw std::runtime_error("Error: Division by zero.");
                result = a / b;
            }
            numbers.push(result);
        }
        else {
            throw std::runtime_error("Error");
        }
    }
    return result;
}