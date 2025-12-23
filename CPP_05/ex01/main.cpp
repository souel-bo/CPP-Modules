/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:59:38 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/23 13:38:24 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "===== TEST 1: Valid Bureaucrat =====" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Invalid Bureaucrat (too high) =====" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: Valid Form =====" << std::endl;
    try
    {
        Form tax("Tax Form", 50, 20);
        std::cout << tax << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: Invalid Form (grade too low) =====" << std::endl;
    try
    {
        Form secret("Secret Form", 151, 10);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 5: Successful signing =====" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 10);
        Form permit("Building Permit", 20, 5);

        alice.signForm(permit);
        std::cout << permit << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 6: Failed signing (grade too low) =====" << std::endl;
    try
    {
        Bureaucrat tom("Tom", 100);
        Form contract("Contract", 50, 30);

        tom.signForm(contract);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
