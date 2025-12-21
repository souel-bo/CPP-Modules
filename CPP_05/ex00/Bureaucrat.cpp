/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:07:37 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/21 11:39:05 by souel-bo         ###   ########.fr       */
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
