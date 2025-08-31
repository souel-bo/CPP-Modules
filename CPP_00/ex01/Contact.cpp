/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 05:00:54 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/01 00:03:15 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


std::string Get_Input(const std::string &promt)
{
    std::string input;
    while (true)
    {
        std::cout << promt;
        if (!std::getline(std::cin, input))
        {
            std::cout<< std::endl;
            std::cout << "EOF detected program rejected" << std::endl;
            exit(0);
        }    
        if (!input.empty())
            return input;
        std::cout << "Empty Input try Another one" << std::endl;
    }
}

void Contact::SetFirstName(const std::string name) {
    firstName = name;
}

void Contact::SetLastName(const std::string name) {
    lastName = name;
}

void Contact::SetNickname(const std::string name) {
    nickName = name;
}

void Contact::SetPhoneNumber(const std::string number) {
    phoneNumber = number;
}

void Contact::SetDarkestSecret(const std::string secret) {
    darkestSecret = secret;
}
