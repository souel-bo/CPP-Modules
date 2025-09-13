/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:08:50 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/13 14:52:35 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string Name) : weapon(NULL), name(Name){}

void HumanB::setWeapon(Weapon & something)
{
    weapon = &something;
}

void HumanB::attack(void)
{
    if (weapon)
        std::cout << name <<" attacks with their " << weapon->get_type() << std::endl;
    else
        std::cout << name << "Has no weapon" << std::endl;
}