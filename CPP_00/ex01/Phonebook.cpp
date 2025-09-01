/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 05:25:06 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/01 17:56:26 by souel-bo         ###   ########.fr       */
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
}
