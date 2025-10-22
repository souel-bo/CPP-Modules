/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:45:05 by souel-bo          #+#    #+#             */
/*   Updated: 2025/10/22 18:06:01 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
    ideas[0] = "BRAIN Is Thinking";
    std::cout << ideas[0] << std::endl;
}

Brain::Brain(const Brain& other){
    *this = other;
}
Brain& Brain::operator=(const Brain& other){
    if (this != &other)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    return *this;
}
Brain::~Brain(){
    std::cout << "Brain Destructor called" << std::endl;
}

