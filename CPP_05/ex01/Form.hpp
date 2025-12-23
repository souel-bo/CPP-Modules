/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:22:11 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/23 13:41:23 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool is_signed;
    const int grade;
    const int execute;

public:
    Form();
    Form(const std::string& Name, int grade_sign, int grade_exec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

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
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif
