/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:00:00 by student          #+#    #+#             */
/*   Updated: 2025/12/25 14:00:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreation", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreation", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


void ShrubberyCreationForm::execute_action(Bureaucrat const& executor) const
{
    (void)executor;
    std::string filename = target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (!outfile)
    {
        std::cerr << "Error creating file: " << filename << std::endl;
        return;
    }

    outfile << "       _-_\n"
               "    /~~   ~~\\\n"
               " /~~         ~~\\\n"
               "{               }\n"
               " \\  _-     -_  /\n"
               "   ~  \\\\ //  ~\n"
               "_- -   | | _- _\n"
               "  _ -  | |   -_\n"
               "      // \\\\\n";
    outfile.close();
    std::cout << "Shrubbery file created: " << filename << std::endl;
}