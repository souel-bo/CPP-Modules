/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:11:37 by souel-bo          #+#    #+#             */
/*   Updated: 2025/10/22 18:32:38 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected :
		std::string type;
	public :
		Animal();
		Animal(const Animal &other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		virtual void makeSound() const = 0;
		std::string getType() const;
} ;

#endif
