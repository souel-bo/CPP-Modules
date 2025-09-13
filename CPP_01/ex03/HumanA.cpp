/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:39:26 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/13 14:49:52 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &something) : weapon(something) , name(Name){}


void HumanA::attack(void)
{
        std::cout << name <<" attacks with their " << weapon.get_type() << std::endl;
}
