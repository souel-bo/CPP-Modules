/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 04:57:01 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/01 17:58:23 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

int main()
{
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
        else if (promt == "SEARCH")
            phonebook.SearchContact();
        else
            std::cout << "Invalid Command Try : (ADD, SEARCH, EXIT)"<< std::endl;
    } while (promt != "EXIT");
}
