/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 02:44:55 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/29 02:53:36 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    Name = "Undefiened";
    hit_point = 100;
    attack_damage = 30;
    enery_point = 100;
    std::cout << "FragTrap default constructor called for " << Name << std::endl;
}
FragTrap::FragTrap(std::string name)
{
    Name = name;
    hit_point = 100;
    attack_damage = 30;
    enery_point = 100;
    std::cout << "FragTrap constructor called for " << Name << std::endl;
}
FragTrap::FragTrap(FragTrap &other)
{
    *this = other;
    std::cout << "FragTrap copy constructor called for " << Name << std::endl;
}
FragTrap& FragTrap::operator=(FragTrap &other)
{
    if (this != &other )
    {
        Name = other.Name;
        hit_point = other.hit_point;
        enery_point = other.enery_point;
        attack_damage = other.attack_damage;
    }
    std::cout << "FragTrap copy assignment operator called for " << Name << std::endl;
    return *this;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << Name << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (hit_point <= 0 || enery_point <= 0) {
        std::cout << "FragTrap " << Name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }
    enery_point--;
    std::cout << "FragTrap " << Name << " attacks " << target
              << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " requests a high five!" << std::endl;
}

int FragTrap::getHitPoints()
{
    return hit_point;
}