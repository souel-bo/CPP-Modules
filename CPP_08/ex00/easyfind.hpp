/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:56:56 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/08 16:26:15 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <list>

template<typename T> void occurence(T &cont, int value){
    typename T::iterator it = std::find(cont.begin(),cont.end(), value);
    if (it != cont.end())
        std::cout << "element found : " << *it << std::endl;
    else 
        throw std::runtime_error("element not found");
}

#endif