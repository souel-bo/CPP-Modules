/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 03:15:19 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/24 03:50:56 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP    
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <algorithm>

class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        void parse_input(int argc, char **argv);
        
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        void process_input();
        void _sortVector(std::vector<int> &arr);
        void _sortDeque(std::deque<int> &arr);
        void _insertInVector(std::vector<int> &mainChain, std::vector<int> &pending);
        void _insertInDeque(std::deque<int> &mainChain, std::deque<int> &pending);
};

#endif