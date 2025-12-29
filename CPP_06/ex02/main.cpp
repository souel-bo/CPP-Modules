/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:08:01 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/29 22:19:26 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <cstdlib>
#include <typeinfo>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
    int randNum = rand() % 3;
    if (randNum == 0)
        return new A();
    else if (randNum == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p){
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "Derived class is A" << std::endl;
        (void)a;
        return;
    } 
    catch (std::bad_cast&) {
        std::cout << "not A" << std::endl;
    }
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "Deived class is B" << std::endl;
        (void)b;
        return;
    } 
    catch (std::bad_cast&) {
        std::cout << "not B" << std::endl;
    }
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "Derived class is C" << std::endl;
        (void)c;
        return;
    }
    catch (std::bad_cast&) {
        std::cout << "not C" << std::endl;
    }
}

int main(){
    srand(time(0));
    Base *basePtr = generate();
    identify(basePtr);
    identify(*basePtr);
    delete basePtr;
}