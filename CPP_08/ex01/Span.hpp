/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:00:32 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/09 17:07:33 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
class Span {
    private :
        unsigned int    _n;
        std::vector<int> _vec;
    public :
        Span();
        Span(unsigned int n);
        Span(const Span &src);
        ~Span();
        Span &operator=(const Span &src);
        void    addNumber(int number);
        int     shortestSpan();
        int     longestSpan();
        class SpanFullException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return "Span is full";
                }
        };
        class NotEnoughNumbersException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return "Not enough numbers to find a span";
                }
        };
        template <typename InputIterator>
        void    addNumbers(InputIterator begin, InputIterator end) {
            for (InputIterator it = begin; it != end; ++it) {
                if (_vec.size() >= _n) {
                    throw SpanFullException();
                }
                _vec.push_back(*it);
            }
        }
};

#endif