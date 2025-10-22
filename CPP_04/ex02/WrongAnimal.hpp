/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:42:07 by souel-bo          #+#    #+#             */
/*   Updated: 2025/10/21 16:42:43 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected :
		std::string type;
	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal();
        void makeSound() const;
		std::string getType() const;
} ;

#endif
