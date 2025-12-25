/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:25:52 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/25 13:49:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), is_signed(false), grade(150), execute_grade(1){}

AForm::AForm(const std::string& Name, int grade_sign, int grade_exec) :
 name(Name),
 grade(grade_sign),
 execute_grade(grade_exec)
 {
    if (grade < 1 || execute_grade < 1)
        throw AForm::GradeTooHighException();
    if (grade > 150 || execute_grade > 150)
        throw AForm::GradeTooLowException();
 }

 AForm::AForm(const AForm& other) : 
 name(other.name), 
 is_signed(other.is_signed),
 grade(other.grade),
 execute_grade(other.execute_grade)
{}
AForm& AForm::operator=(const AForm& other){
    if (this != &other)
       this->is_signed = other.is_signed;
    return *this;
}

AForm::~AForm(){}

const char *AForm::GradeTooHighException::what() const throw(){
    return "grade form to hight";
}

const char *AForm::GradeTooLowException::what() const throw(){
    return "grade form to loow";
}

const std::string &::AForm::get_Name() const{
    return name;
}

bool::AForm::get_Signature() const{
    return is_signed;
}
 int ::AForm::get_Grade() const {
    return grade;
}
 int ::AForm::get_Exec() const {
    return execute_grade;
}
std::ostream& operator<<(std::ostream &os, const AForm & form){
    os << form.get_Name() << " grade : " << form.get_Grade() << " "<< form.get_Signature() << std::endl;
    return os;
}
void::AForm::beSigned(Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > get_Grade())
        throw AForm::GradeTooLowException();
    is_signed = true;    
}

void::AForm::execute(Bureaucrat const &bureaucrat) const {
    if (!is_signed)
        throw AForm::GradeTooLowException();
    if (bureaucrat.getGrade() > execute_grade)
        throw AForm::GradeTooLowException();
    execute_action(bureaucrat);
}
