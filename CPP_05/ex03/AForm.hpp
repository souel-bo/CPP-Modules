/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:22:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/25 21:26:23 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool is_signed;
    const int grade;
    const int execute_grade;

public:
    AForm();
    AForm(const std::string& Name, int grade_sign, int grade_exec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    const std::string& get_Name() const;
    bool get_Signature() const;
    int get_Grade() const;
    int get_Exec() const;

    void beSigned(Bureaucrat &bureaucrat);
    void execute(Bureaucrat const &executor) const;
    virtual void execute_action(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm &form);

#endif
