/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 04:56:19 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/29 02:51:30 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== Creating a FragTrap ===" << std::endl;
    FragTrap frag("Alice");

    std::cout << "\n=== Testing attack ===" << std::endl;
    frag.attack("Enemy");

    std::cout << "\n=== Testing special ability ===" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n=== Modifying inherited attributes ===" << std::endl;
    frag.takeDamage(30);
    frag.beRepaired(20);

    std::cout << "\n=== Checking remaining health ===" << std::endl;
    std::cout << "Remaining hit points: " << frag.getHitPoints() << std::endl;

    std::cout << "\n=== Ending main, destructors called ===" << std::endl;
    return 0;
}
