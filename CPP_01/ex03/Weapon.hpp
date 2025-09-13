/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:53:08 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/13 14:49:08 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class  Weapon
{
    private :
    std::string type;
    public :
    Weapon(std::string name);
    const std::string & get_type();
    void setType(std::string  ref);
};

#include "HumanB.hpp"
#include "HumanA.hpp"

#endif