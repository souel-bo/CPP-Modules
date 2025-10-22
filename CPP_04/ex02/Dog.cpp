/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:38:49 by souel-bo          #+#    #+#             */
/*   Updated: 2025/10/22 18:07:54 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
    type = "Dog";
    std::cout << type << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog& other){
    *this = other;
}
Dog& Dog::operator=(const Dog& other){
    if (this != &other)
        this->type = other.type;
    return *this;
}
Dog::~Dog(){
    std::cout << "Dog Destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const{
    std::cout << "WOOF" << std::endl;
}

std::string Dog::getType() const
{
    return type;
}