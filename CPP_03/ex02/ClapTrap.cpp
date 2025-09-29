/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 05:04:08 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/28 05:30:22 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    Name = "Undefiened";
    hit_point = 10;
    attack_damage = 0;
    enery_point = 10;
    std::cout << "ClapTrap default constructor called for " << Name << std::endl;
}
ClapTrap::ClapTrap(std::string name)
{
    Name = name;
    hit_point = 10;
    attack_damage = 0;
    enery_point = 10;
    std::cout << "ClapTrap constructor called for " << Name << std::endl;
}
ClapTrap::ClapTrap(ClapTrap &other)
{
    *this = other;
    std::cout << "ClapTrap copy constructor called for " << Name << std::endl;
}
ClapTrap& ClapTrap::operator=(ClapTrap &other)
{
    if (this != &other )
    {
        Name = other.Name;
        hit_point = other.hit_point;
        enery_point = other.enery_point;
        attack_damage = other.attack_damage;
    }
    std::cout << "ClapTrap copy assignment operator called for " << Name << std::endl;
    return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << Name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (hit_point <= 0 || enery_point <= 0) {
        std::cout << "ClapTrap " << Name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }
    enery_point--;
    std::cout << "ClapTrap " << Name << " attacks " << target
              << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

    if (hit_point <= 0 )
    {
        std::cout << "already dead" << std::endl;
        return;
    }
    hit_point -= amount;
    if (hit_point < 0)
        hit_point = 0;
    std::cout << "ClapTrap " << Name << " takes " << amount
              << " damage! Remaining HP: " << hit_point << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hit_point <= 0 || enery_point <= 0) {
        std::cout << "ClapTrap " << Name << " has no energy or hit points left to repair!" << std::endl;
        return;
    }
    hit_point += amount;
    enery_point--;
    std::cout << "ClapTrap " << Name << " repairs itself, recovering " << amount
              << " HP! Current HP: " << hit_point << std::endl;
}
