/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:30:27 by souel-bo          #+#    #+#             */
/*   Updated: 2025/10/21 14:54:43 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat(){
    type = "Cat";
}

Cat::Cat(const Cat& other){
    *this = other;
}
Cat& Cat::operator=(const Cat& other){
    if (this != &other)
        this->type = other.type;
    return *this;
}
Cat::~Cat(){
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "MEAOW" << std::endl;
}

std::string Cat::getType() const
{
    return type;
}