/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:51:20 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/02 23:03:01 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
template <typename T>
class Array {
   private:
        T* data;
        size_t size;
    public:
        Array() : data(NULL), size(0) {}
        Array(unsigned int n) : data(new T[n]()), size(n) {}
        Array(const Array &other) : data(new T[other.size]()), size(other.size) {
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        Array& operator=(const Array &other) {
            if (this != &other) {
                delete[] data;
                size = other.size;
                data = new T[size]();
                for (size_t i = 0; i < size; ++i) {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }
        ~Array() {
            delete[] data;
        }
        T& operator[](size_t index) {
            if (index >= size) {
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }
        const T& operator[](size_t index) const {
            if (index >= size) {
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }
        size_t getSize() const {
            return size;
        }
};

#endif