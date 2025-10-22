/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:41:22 by souel-bo          #+#    #+#             */
/*   Updated: 2025/10/21 16:41:55 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("unknown"){}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
    *this = other;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if (this != &other)
        this->type = other.type;
    return *this;
}
WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongANIMAL SOUND" << std::endl;
}
std::string WrongAnimal::getType() const
{
    return type;
}