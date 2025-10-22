/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:29:08 by souel-bo          #+#    #+#             */
/*   Updated: 2025/10/22 17:56:34 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private :
		Brain *brain;
	public :
		Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat& other);
		~Cat();
		void makeSound() const;
		std::string getType() const;
} ;

#endif
