/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 05:25:06 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/01 00:02:25 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
    index = 0;
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
}
