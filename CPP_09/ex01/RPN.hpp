/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:22:53 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/24 18:07:25 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <string>

class RPN
{
    private:
        std::stack<int> numbers;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        void evaluate(const std::string &expression);
        int is_operator(const std::string &token);
        void process_operation(const std::string &expression);
};

#endif