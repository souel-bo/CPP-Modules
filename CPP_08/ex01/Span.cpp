/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:11:03 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/09 17:21:38 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {}
Span::Span(unsigned int n) : _n(n) {}
Span::Span(const Span &src) : _n(src._n), _vec(src._vec) {}
Span::~Span() {}
Span &Span::operator=(const Span &src) {
    if (this != &src) {
        _n = src._n;
        _vec = src._vec;
    }
    return *this;
}
void Span::addNumber(int number) {
    if (_vec.size() >= _n) {
        throw SpanFullException();
    }
    _vec.push_back(number);
}
int Span::shortestSpan() {
    if (_vec.size() < 2) {
        throw NotEnoughNumbersException();
    }
    std::vector<int> sortedVec = _vec;
    std::sort(sortedVec.begin(), sortedVec.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedVec.size(); ++i) {
        int span = sortedVec[i] - sortedVec[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}
int Span::longestSpan() {
    if (_vec.size() < 2) {
        throw NotEnoughNumbersException();
    }
    int minElement = *std::min_element(_vec.begin(), _vec.end());
    int maxElement = *std::max_element(_vec.begin(), _vec.end());
    return maxElement - minElement;
}

