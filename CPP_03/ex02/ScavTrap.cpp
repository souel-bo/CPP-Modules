/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 01:01:15 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/29 01:22:17 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    Name = "Undefiened";
    hit_point = 100;
    attack_damage = 20;
    enery_point = 50;
    std::cout << "ScavTrap default constructor called for " << Name << std::endl;
}
ScavTrap::ScavTrap(std::string name)
{
    Name = name;
    hit_point = 100;
    attack_damage = 20;
    enery_point = 50;
    std::cout << "ScavTrap constructor called for " << Name << std::endl;
}
ScavTrap::ScavTrap(ScavTrap &other)
{
    *this = other;
    std::cout << "ScavTrap copy constructor called for " << Name << std::endl;
}
ScavTrap& ScavTrap::operator=(ScavTrap &other)
{
    if (this != &other )
    {
        Name = other.Name;
        hit_point = other.hit_point;
        enery_point = other.enery_point;
        attack_damage = other.attack_damage;
    }
    std::cout << "ScavTrap copy assignment operator called for " << Name << std::endl;
    return *this;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << Name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (hit_point <= 0 || enery_point <= 0) {
        std::cout << "ScavTrap " << Name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }
    enery_point--;
    std::cout << "ScavTrap " << Name << " attacks " << target
              << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}