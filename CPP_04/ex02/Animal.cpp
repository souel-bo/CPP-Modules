/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:27:32 by souel-bo          #+#    #+#             */
/*   Updated: 2025/10/22 18:37:18 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("unknown"){}

Animal::Animal(const Animal& other){
    *this = other;
}
Animal& Animal::operator=(const Animal& other){
    if (this != &other)
        this->type = other.type;
    return *this;
}
Animal::~Animal(){
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}