/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:07:37 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/25 13:49:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int Grade) : Name(name) {
    if (Grade < 1)
       throw Bureaucrat::GradeTooHighException();
    if (Grade > 150)
        throw Bureaucrat::GradeTooLowException();
    grade = Grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : Name(other.Name), grade(other.grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const{
    return Name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::Increment_Grade(){
    grade--; 
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Grade after increment : " << grade << std::endl;
}

void Bureaucrat::Decrement_Grade(){
    grade++;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Grade after Decrement : " << grade << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}
void ::Bureaucrat::signForm(AForm &form){
    form.beSigned(*this);
    if (form.get_Signature())
        std::cout << *this << " signed " << form << std::endl;
    else
        std::cout << *this << "couldn't sign" << form << "because : grade too low" << std::endl; 
}

void ::Bureaucrat::executeForm(AForm const &form){
    try {
        form.execute(*this);
        std::cout << *this << " executed " << form.get_Name() << std::endl;
    } catch (std::exception &e) {
        std::cout << *this << " could not execute " << form.get_Name() << " because : " << e.what() << std::endl;
    }
}