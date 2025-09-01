/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 05:25:06 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/01 20:42:17 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
    index = 0;
    count = 0;
}

void Phonebook::AddContact() {
    if (index == 8)
        index = 0;
    contact[index].SetFirstName(Get_Input("First Name : "));
    contact[index].SetLastName(Get_Input("Last Name : "));
    contact[index].SetNickname(Get_Input("Nickname : "));
    contact[index].SetPhoneNumber(Get_Input("Phone Number : "));
    contact[index].SetDarkestSecret(Get_Input("Darkest Secret : "));
    index++;
    if (count < 8)
        count++;
}

int Phonebook::valid(std::string &promt){
    if (promt.length() != 1 || (promt[0] < '0' || promt[0] > '7')){
        std::cout << "Index Must be between 0 & 7" << std::endl;
        return -1;
    }
    int i = promt[0] - '0';
    if (contact[i].GetFirstName().empty()){
        std::cout << "No contact found at index : " << i << std::endl;
        return -1;
    }
    return i;
}

void Phonebook::SearchContact(){
    if (index == 0)
    {
        std::cout << "Phonebook is empty, please add a contact first." << std::endl;
        return ;
    }
        std::cout << "-------------------------------------------------" << std::endl;
        std::cout << std::setw(10) << "Index" << "|"
          << std::setw(10) << "First Name" << "|"
          << std::setw(10) << "Last Name" << "|"
          << std::setw(10) << "Nickname" << std::endl;
        std::cout << "-------------------------------------------------" << std::endl;
    for (int i = 0; i < count; i++){
        std::cout << std::setw(10) << i << "|" 
        << std::setw(10) <<truncate(contact[i].GetFirstName()) << "|"
        << std::setw(10) <<truncate(contact[i].GetLastName()) << "|"
        << std::setw(10) <<truncate(contact[i].GetNickName()) << std::endl;
    }
    std::string promt;
    int i;
    while (true)
    {
        std::cout << "Enter a contact index : ";
        if (!std::getline(std::cin, promt))
        {
            std::cout<< std::endl;
            std::cout << "EOF detected program rejected" << std::endl;
            exit(0);
        }
        i = valid(promt);
        if (i != -1)
            break;
    }
    std::cout << std::endl;
    std::cout << "First name : " << contact[i].GetFirstName() << std::endl;
    std::cout << "Last name : " << contact[i].GetLastName() << std::endl;
    std::cout << "Nickname : " << contact[i].GetNickName() << std::endl;
    std::cout << "Phone Number : " << contact[i].GetPhoneNumber() << std::endl;
    std::cout << "Darkest Secret : " << contact[i].DarkestSecret() << std::endl;
    std::cout << std::endl;
}
