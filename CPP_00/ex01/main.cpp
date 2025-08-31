/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 04:57:01 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/31 23:42:53 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

int main()
{
    Contact contact;
    Phonebook phonebook;
    std::string promt;

    std::cout << "Welcome to PhoneBook!" << std::endl;
    std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
    do {
        std::cout << "Enter command: ";
        if (!std::getline(std::cin, promt))
        {
            std::cout<< std::endl;
            std::cout << "EOF detected program rejected" << std::endl;
            exit(0);
        }   
        if (promt == "ADD")
            phonebook.AddContact();
    } while (promt != "EXIT");
}
