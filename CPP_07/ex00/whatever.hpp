/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:51:54 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/02 22:51:54 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
template <typename T> void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T> T min(const T &a, const T &b) {
    return (a < b ? a : b);
}
template <typename T> T max(const T &a, const T &b) {
    return (a > b ? a : b);
}

#endif