/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:45:28 by souel-bo          #+#    #+#             */
/*   Updated: 2025/10/22 18:00:34 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
    private :
        std::string ideas[100];
	public :
		Brain();
		Brain(const Brain &other);
		Brain& operator=(const Brain& other);
		~Brain();
} ;

#endif
