/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 04:57:01 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/30 05:14:56 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

int main()
{
    Contact contact;
    Phonebook phonebook;
    std::string promt;

    do {
        std::cin >> promt;
        std::cout << promt << std::endl;
    } while (promt != "EXIT");
}