/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:18:14 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/08 16:25:49 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(){
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(100);
    vec.push_back(3);
    try {
        occurence(vec, 3);
        occurence(vec, 4);
    }
    catch(std::runtime_error &e){
        std::cout << e.what();
    }
}