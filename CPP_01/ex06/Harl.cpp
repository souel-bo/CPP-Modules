/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 06:14:38 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/18 06:49:38 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug() 
{   
        std::cout << "[ DEBUG ]\n";
        std::cout << "I love having extra bacon for my burger. I really do!" << std::endl;
}
void Harl::info()
{
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]\n";
        std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error() 
{
    std::cout << "[ ERROR ]\n";
        std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int check(std::string &level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            return i;
    }
    return -1;
}

void Harl::complain(std::string level)
{
    void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    switch (check(level))
    {
        case 0:
            (this->*functions[0])();
        case 1:
            (this->*functions[1])();
        case 2:
            (this->*functions[2])();
        case 3:
            (this->*functions[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

