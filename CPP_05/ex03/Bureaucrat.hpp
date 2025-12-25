/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:01:00 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/25 13:49:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
    private:
        const std::string Name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int Grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        const std::string& getName() const;
        int getGrade() const;
        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char * what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char * what() const throw();
        };
        void Increment_Grade();
        void Decrement_Grade();
        void signForm(AForm &form);
        void executeForm(AForm const &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif