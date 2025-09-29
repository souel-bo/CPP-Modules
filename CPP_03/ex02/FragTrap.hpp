/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 02:45:09 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/29 02:53:29 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
    private :
        std::string Name;
        int hit_point;
        int enery_point;
        int attack_damage;
    public :
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap &other);
        FragTrap& operator=(FragTrap &other);
        ~FragTrap();
        void attack(const std::string& target);
        void  highFivesGuys(void);
        int getHitPoints();
};

#endif
