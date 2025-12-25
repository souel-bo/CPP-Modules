/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:48:40 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/25 21:28:47 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

const char * Intern::InternException::what() const throw(){
	return "Intern Error: Form not found";
}

AForm *::Intern::makeForm(const std::string &formName, const std::string &target)
{
	AForm *form = NULL;
	std::string forms[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm",
	};
	int form_index = -1;
	for (int i = 0; i < 3; i++){
		if (formName == forms[i]){
			form_index = i;
			break;
		}
	}
	switch(form_index)
	{
		case 0 :
			form = new ShrubberyCreationForm(target);
			break;
		case 1 :
			form = new RobotomyRequestForm(target);
			break;
		case 2 :
			form = new PresidentialPardonForm(target);
			break;
		default :
			throw Intern::InternException();
	}
	std::cout << "Intern creates" << form->get_Name() << std::endl;
	return form;                                                                                       
}

