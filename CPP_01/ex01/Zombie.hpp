/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:55:58 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/11 19:43:52 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
    private :
        std::string name;
    public :
        Zombie();
        void set_name(std::string Name);
        void announce( void );
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif