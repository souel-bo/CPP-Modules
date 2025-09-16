/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:24:29 by souel-bo          #+#    #+#             */
/*   Updated: 2025/09/16 18:21:15 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

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
    std::string newfile = argv[1];
    newfile += ".replace";
    std::ofstream outfile(newfile.c_str());
    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(argv[2], pos)) != std::string::npos) {
            line = line.substr(0, pos) + argv[3] + line.substr(pos + std::strlen(argv[2]));
            pos += std::strlen(argv[3]);
        }
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
}
