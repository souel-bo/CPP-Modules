/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 06:14:38 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/18 06:23:33 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug() 
{
            std::cout << "I love having extra bacon for my burger. I really do!" << std::endl;
}
void Harl::info()
{
        std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
}

void Harl::warning()
{
        std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error() 
{
        std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "Unknown level: " << level << std::endl;
}
