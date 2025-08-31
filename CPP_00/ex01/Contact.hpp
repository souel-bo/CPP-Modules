/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 04:44:22 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/01 00:01:31 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstdlib>

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
};

std::string Get_Input(const std::string &promt);
#endif