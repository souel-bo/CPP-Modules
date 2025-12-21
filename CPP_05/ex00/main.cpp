/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:27:51 by souel-bo          #+#    #+#             */
/*   Updated: 2025/12/21 11:42:21 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "TEST" << std::endl;
	try
	{
		Bureaucrat b1("test", 1);
		std::cout << b1 << std::endl;
		b1.Decrement_Grade();
        b1.Increment_Grade();
        b1.Increment_Grade();
        
    }
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}