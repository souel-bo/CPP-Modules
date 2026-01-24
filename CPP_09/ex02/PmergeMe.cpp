/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 03:20:10 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/24 04:14:52 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv){
    try {
        parse_input(argc, argv);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(1);
    }
}

PmergeMe::PmergeMe(const PmergeMe &other){
    this->vec = other.vec;
    this->deq = other.deq;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
    if (this != &other){
        this->vec = other.vec;
        this->deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void::PmergeMe ::parse_input(int argc, char **argv){
    for (int i = 1; i < argc; ++i){
        int num = std::atoi(argv[i]);
        if (num < 0)
            throw std::invalid_argument("Negative numbers are not allowed.");
        std::string str(argv[i]);
        for (size_t j = 0; j < str.length(); ++j){
            if (!std::isdigit(str[j]))
                throw std::invalid_argument("Invalid input: Non-integer value found.");
        }
        vec.push_back(num);
        deq.push_back(num);
    }
}

void PmergeMe::process_input(){
    std::vector<int> vecCopy = vec;
    std::deque<int> deqCopy = deq;
    std::cout << "Before: ";
    size_t limit = vec.size();
    if (limit > 5)
        limit = 5;
    for (size_t i = 0; i < limit; ++i)
        std::cout << vec[i] << " ";
    if (vec.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
    clock_t startVec = std::clock();
    _sortVector(vec);
    clock_t endVec = std::clock();
    clock_t startDeq = std::clock();
    _sortDeque(deq);
    clock_t endDeq = std::clock();
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    double timeVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = double(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << vecCopy.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deqCopy.size() << " elements with std::deque : " << timeDeq << " us" << std::endl;
}


void PmergeMe::_sortVector(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return;
    std::vector<int> larger;
    std::vector<int> smaller;
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (arr.size() % 2 != 0);
    if (hasStraggler) 
        straggler = arr.back();
    size_t end = arr.size();
    if (hasStraggler)
        end = arr.size() - 1;
    for (size_t i = 0; i < end; i += 2)
    {
        int n1 = arr[i];
        int n2 = arr[i+1];
        if (n1 > n2) 
            pairs.push_back(std::make_pair(n1, n2));
        else         
            pairs.push_back(std::make_pair(n2, n1));
    }
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        larger.push_back(pairs[i].first);
    }
    _sortVector(larger); // 8 5 6 1  || 8 6
    std::vector<int> mainChain = larger;
    std::vector<int> pending;
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        int target = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == target)
            {
                pending.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    if (hasStraggler)
        pending.push_back(straggler);
    mainChain.insert(mainChain.begin(), pending[0]);
    _insertInVector(mainChain, pending);
    arr = mainChain;
}

void PmergeMe::_insertInVector(std::vector<int> &mainChain, std::vector<int> &pending)
{
    size_t jacobSeq[] =
    {
        1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923
    };
    size_t n = 0;
    size_t pendingIndex = 1;
    while (pendingIndex < pending.size())
    {
        size_t nextLimit = jacobSeq[n + 1]; 
        if (nextLimit >= pending.size())
            nextLimit = pending.size() - 1;

        for (size_t i = nextLimit; i >= pendingIndex; --i)
        {
            int value = pending[i];
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
            mainChain.insert(pos, value);
        }
        pendingIndex = nextLimit + 1;
        n++;
    }
}

void PmergeMe::_sortDeque(std::deque<int> &arr)
{
    if (arr.size() <= 1)
        return;
    std::deque<int> larger;
    std::deque<int> smaller;
    std::deque<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (arr.size() % 2 != 0);
    if (hasStraggler)
        straggler = arr.back();
    size_t end = arr.size();
    if (hasStraggler)
        end = arr.size() - 1;
    for (size_t i = 0; i < end; i += 2)
    {
        int n1 = arr[i];
        int n2 = arr[i+1];
        if (n1 > n2)
            pairs.push_back(std::make_pair(n1, n2));
        else
            pairs.push_back(std::make_pair(n2, n1));
    }
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        larger.push_back(pairs[i].first);
    }
    _sortDeque(larger);
    std::deque<int> mainChain = larger;
    std::deque<int> pending;
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        int target = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == target)
            {
                pending.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }
    if (hasStraggler) 
        pending.push_back(straggler);
    mainChain.push_front(pending[0]);
    _insertInDeque(mainChain, pending);
    arr = mainChain;
}

void PmergeMe::_insertInDeque(std::deque<int> &mainChain, std::deque<int> &pending)
{
    size_t jacobSeq[] =
    {
        1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923
    };
    size_t n = 0;
    size_t pendingIndex = 1;

    while (pendingIndex < pending.size())
    {
        size_t nextLimit = jacobSeq[n + 1]; 
        if (nextLimit >= pending.size())
            nextLimit = pending.size() - 1;

        for (size_t i = nextLimit; i >= pendingIndex; --i)
        {
            int value = pending[i];
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
            mainChain.insert(pos, value);
        }
        pendingIndex = nextLimit + 1;
        n++;
    }
}