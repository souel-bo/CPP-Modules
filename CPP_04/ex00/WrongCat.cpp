/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:43:36 by souel-bo          #+#    #+#             */
/*   Updated: 2025/10/21 16:43:37 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat(){
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other){
    *this = other;
}
WrongCat& WrongCat::operator=(const WrongCat& other){
    if (this != &other)
        this->type = other.type;
    return *this;
}
WrongCat::~WrongCat(){
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "MEAOW" << std::endl;
}

std::string WrongCat::getType() const
{
    return type;
}