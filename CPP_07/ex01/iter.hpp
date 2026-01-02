/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:51:46 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/02 22:51:46 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(T &)) {
    if (array == NULL || func == NULL)
        return;
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T>
void iter (const T *array, size_t length, void (*func)(const T &)) {
    if (array == NULL || func == NULL)
        return;
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif