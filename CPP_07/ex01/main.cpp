/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:51:43 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/02 22:51:43 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print(const int &x){
    std::cout << x << std::endl;
}
void increment(int &x){
    x += 1;
}

int main(){
    int arr[] = {1, 2, 3};
    const int carr[] = {4, 5, 6};
    // iter(arr, 3, NULL);
    iter(arr, 3, increment);        // modifies arr
    iter(carr, 3, print);  // prints carr

}