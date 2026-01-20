/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:18:42 by souel-bo          #+#    #+#             */
/*   Updated: 2026/01/20 16:34:23 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    try {
        loadData("data.csv");
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    // loadData("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
    this->data = other.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    if (this != &other){
        this->data = other.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::loadData(const std::string& filename){
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: Could not open data file.");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)){
        std::istringstream ss(line);
        std::string date;
        double value;
        if (std::getline(ss, date, ',') && ss >> value){
            data[date] = value;
            // std::cout << "Loaded: " << date << " -> " << value << std::endl;
        }
    }
    file.close();
}

void BitcoinExchange::processInputFile(const std::string& filename){
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: Could not open input file.");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)){
        std::stringstream ss(line);
        std::string date, seperator;
        double amount;
        if (ss >> date >> seperator && seperator == "|" && ss >> amount){
            try {
                validate_date(date);
                validate_amount(amount);
                std::map<std::string, double>::iterator it = data.lower_bound(date);
                if (it == data.end()  && it->first != date && it != data.begin()){
                    --it;
                }
                double result = amount * it->second;
                std::cout << date << " => " << amount << " = " << result << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "Error processing line: " << line << " - " << e.what() << std::endl;
            }
        }
        else {
            std::cerr << "Error: Invalid line format: " << line << std::endl;
        }
    }
}

void BitcoinExchange::validate_date(const std::string& date){
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::invalid_argument("Invalid date format. Expected YYYY-MM-DD.");
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12)
        throw std::out_of_range("Month must be between 1 and 12.");
    if (day < 1 || day > 31)
        throw std::out_of_range("Day must be between 1 and 31.");
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::out_of_range("Day must be between 1 and 30 for the given month.");
    if (month == 2 && day > 29)
        throw std::out_of_range("Day must be between 1 and 29 for February.");
}

void BitcoinExchange::validate_amount(double amount){
    if (amount < 0)
        throw std::out_of_range("Amount must be non-negative.");
    if (amount > 1000)
        throw std::out_of_range("Amount must not exceed 1000.");
}