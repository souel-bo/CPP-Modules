/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:24:57 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/25 17:45:17 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        // Bureaucrats
        Bureaucrat boss("Alice", 1);
        Bureaucrat mid("Bob", 75);
        Bureaucrat intern("Charlie", 150);

        std::cout << boss << std::endl;
        std::cout << mid << std::endl;
        std::cout << intern << std::endl;

        // Forms
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bob");
        PresidentialPardonForm pardon("Charlie");

        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        // Signing forms
        // intern.signForm(shrub); // should fail
        mid.signForm(shrub);    // should succeed
        boss.signForm(pardon);  // should succeed
        // mid.signForm(robot);    // should fail
        boss.signForm(robot);   // should succeed

        std::cout << std::endl;

        // Executing forms
        // intern.executeForm(shrub); // fail, grade too low
        mid.executeForm(shrub);    // succeed
        boss.executeForm(pardon);  // succeed
        // mid.executeForm(robot);    // fail, not signed or grade too low
        boss.executeForm(robot);   // succeed, random success/failure

    } catch (std::exception &e) {
        std::cout << "Exception caught in main: " << e.what() << std::endl;
    }
}
