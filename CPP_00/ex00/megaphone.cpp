/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:05:50 by souel-bo          #+#    #+#             */
/*   Updated: 2025/08/26 13:35:30 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void capitalize(char **argv, int argc)
{
    char upper;
    for(int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
            {
                upper = toupper(argv[i][j]);
                std::cout << upper;  
            }
            else
                std::cout << argv[i][j];
        }
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    else
        capitalize(argv, argc);
}