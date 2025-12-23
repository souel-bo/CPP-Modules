/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:01:00 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/23 13:29:17 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include "Form.hpp"

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
        void signForm(Form &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif