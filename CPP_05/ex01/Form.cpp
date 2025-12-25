/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:25:52 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/25 13:57:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), is_signed(false), grade(150), execute(1){}

Form::Form(const std::string& Name, int grade_sign, int grade_exec) :
 name(Name),
 grade(grade_sign),
 execute(grade_exec)
 {
    if (grade < 1 || execute < 1)
        throw Form::GradeTooHighException();
    if (grade > 150 || execute > 150)
        throw Form::GradeTooLowException();
 }

 Form::Form(const Form& other) : 
 name(other.name), 
 is_signed(other.is_signed),
 grade(other.grade),
 execute(other.execute)
{}
Form& Form::operator=(const Form& other){
    if (this != &other)
       this->is_signed = other.is_signed;
    return *this;
}

Form::~Form(){}

const char *Form::GradeTooHighException::what() const throw(){
    return "grade form to hight";
}

const char *Form::GradeTooLowException::what() const throw(){
    return "grade form to loow";
}

const std::string &::Form::get_Name() const{
    return name;
}

bool::Form::get_Signature() const{
    return is_signed;
}
 int ::Form::get_Grade() const {
    return grade;
}
 int ::Form::get_Exec() const {
    return execute;
}
std::ostream& operator<<(std::ostream &os, const Form & form){
    os << form.get_Name() << " grade : " << form.get_Grade() << " "<< form.get_Signature() << std::endl;
    return os;
}
void::Form::beSigned(Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > get_Grade())
        throw Form::GradeTooLowException();
    is_signed = true;    
}
