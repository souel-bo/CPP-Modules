/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:24:57 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/25 17:58:31 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() { 
    try { 
        Bureaucrat boss("boss", 1);
        Bureaucrat mid("mid", 143);
        ShrubberyCreationForm shruby("tree");
        ShrubberyCreationForm shr("throw");
        shruby.beSigned(boss);
        shr.beSigned(mid);
        shruby.execute(boss);
        shr.execute(mid);
    } 
    catch (std::exception &e) { 
        std::cout << "Exception caught in main: " << e.what() << std::endl;
    }
}
