/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 04:56:19 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/29 01:19:10 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Creating a ScavTrap ===" << std::endl;
    ScavTrap scav("Bob");

    std::cout << "\n=== Testing attack ===" << std::endl;
    scav.attack("Enemy");

    std::cout << "\n=== Testing special ability ===" << std::endl;
    scav.guardGate();

    std::cout << "\n=== Modifying inherited attributes ===" << std::endl;
    scav.takeDamage(20);
    scav.beRepaired(10);

    std::cout << "\n=== Ending main, destructors called ===" << std::endl;
    return 0;
}
