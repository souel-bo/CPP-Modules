/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 04:44:22 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/01 20:40:50 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    void SetFirstName(const std::string name);
    void SetLastName(const std::string lastName);
    void SetNickname(const std::string nickname);
    void SetPhoneNumber(const std::string phoneNumber);
    void SetDarkestSecret(const std::string darkestSecret);
    std::string GetFirstName();
    std::string GetLastName();
    std::string GetNickName();
    std::string GetPhoneNumber();
    std::string DarkestSecret();
};

std::string Get_Input(const std::string &promt);
std::string truncate(std::string str);

#endif