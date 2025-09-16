/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:24:29 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/16 07:37:07 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string.h>

int main(int argc, char **argv){
    if (argc != 4)
    {
        std::cout << "WRONG NUMBER OF ARGUMENT !!" << std::endl;
        return 1;
    }
    std::ifstream infile(argv[1]);
    if (!infile.is_open())
    {
        std::cout << "INVALID FILE" << std::endl;
        return 1;
    }
    if (argv[2][0] == '\0')
    {
        std::cout << "INVALID ARGUMENT" << std::endl;
        return 1;
    }
    std::string line;
    std::ofstream outfile("outfile.txt");
    while (std::getline(infile, line))
    {
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
}
