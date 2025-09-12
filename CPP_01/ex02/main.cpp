/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:28:01 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/12 15:35:11 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &ref = str;

    std::cout <<"adress of str : "<< &str << std::endl;
    std::cout <<"adress of stringPTR : "<< stringPTR << std::endl;
    std::cout <<"adress of ref : "<< &ref << std::endl;
    std::cout <<"value of str : "<< str << std::endl;
    std::cout <<"value of stringPTR : "<< *stringPTR << std::endl;
    std::cout <<"value of ref : "<< ref << std::endl;
}