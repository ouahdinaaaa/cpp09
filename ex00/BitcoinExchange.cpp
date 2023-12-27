/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:16:55 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/25 22:16:55 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filename) : _data(), index(0) {
    (void)filename;
    parser_csv("data2.csv");
    // parserDate();
}


void    BitcoinExchange::parser_csv(const std::string &filename)
{
    const std::string filee = filename;
    std::ifstream file(filename.c_str());
    std::string date;
    std::string line;
    // float exchange_rate;

    if (!file.is_open()){
        std::cout << "Error of file cannot open !!! " << std::endl;
    }
    while (getline(file, date, ','))
    {
        getline(file, line);
        std::cout << "date is ["<< date << "] and value is [" << line << "]" << std::endl; 
    }
}

void BitcoinExchange::parser(const std::string& filename, int boleen) {
    const std::string file_str = filename;
    std::ifstream file(file_str.c_str());
    std::string line;
    int boucle = boleen -1;

    if (!file.is_open()) {
        std::cout << "Error of file cannot open !!!" << std::endl;
        exit(1);
    }

    while (std::getline(file, line)) {
        if (!line.empty() && boucle-- < 0) {
            parse_line(line, boleen);
        }
    }
    file.close();
}

std::string AddDate2(int years, int month, int day) 
{
    std::stringstream ss;
    ss << years << month << day;
    return ss.str();
}

void BitcoinExchange::parse_line(const std::string& line, int boleen) {
    int years, month, day, value;
    // float exchangeRate;
    std::string date, _olDate2, _date2;
    
    years = parserYears(line, 0);
    month = parserMonth(line, this->index);
    day = parserDay(line, this->index);
    value = parserValue(line, this->index, boleen);
    date = line;
    // exchangeRate = 0;
    _olDate2 = "";
    _date2 = AddDate2(years, month, day);
    if (day == -1 || month == -1 || years == -1) {
        std::cout << "bad input -> " + line << std::endl;
        exit (0);
    }
    if (value == -2) {
        std::cout << "Error : Number is not positive" << std::endl;
    }
    if (value == -3) {
        std::cout << "Error : Number too large a number" << std::endl;
        exit (0);
    }
    // _data.insert(std::make_pair(, value));
}

int    BitcoinExchange::parserYears(const std::string &line, int index)
{
    std::string years;
    int         years_nb;

    while (line[index] && ((line[index] >= 9 && line[index] <= 13) || line[index] == ' '))
        index++;
    while (line[index]){
        if (!std::isdigit(line[index]) )
            break ;
        years.push_back(line[index]);
        index++;
    }
    years_nb = std::atoi(years.c_str());
    if (years_nb < 0 || years_nb > 2024){
        return -1;
    }
    this->index = index;
    return years_nb;
}

int    BitcoinExchange::parserMonth(const std::string &line, int index)
{
    std::string     month;
    int             month_nb;
    
    if (!line[index] || !line[index + 1]|| line[index] != '-'){
        return -1;
    }
    index++;
    while (line[index] && ((line[index] >= 9 && line[index] <= 13) || line[index] == ' '))
        index++;
    while (line[index]){
        if (!std::isdigit(line[index]))
            break ;
        month.push_back(line[index]);
        index++;
    }
    month_nb = std::atoi(month.c_str());
    if (month_nb < 1 || month_nb > 12){
        return -1;
    }
    this->index = index;
    return month_nb;
}

int    BitcoinExchange::parserDay(const std::string &line, int index)
{
    std::string day;
    int         day_nb;

    if (!line[index] || line[index] != '-' || !line[index + 1]){
        return -1;
    }
    index++;
    while (line[index] && ((line[index] >= 9 && line[index] <= 13) || line[index] == ' '))
        index++;
    while (line[index]){
        if (!std::isdigit(line[index]))
            break ;
        day.push_back(line[index]);
        index++;
    }
    day_nb = std::atoi(day.c_str());
    if (day_nb < 1 || day_nb > 31){
        return -1;
    }
    this->index = index;
    return day_nb;   
}

float     BitcoinExchange::parserValue(const std::string &line, int index, int boleen)
{
    std::string value;
    float value_nb;
    char    str;
    
    if (boleen)
        str = ',';
    else
        str = '|';
    if (!(line[index] >= 9 && line[index] <= 13) && line[index] != str && line[index] != ' '){
        return -1;
    }
    while (line[index] && ((line[index] >= 9 && line[index] <= 13) || line[index] == ' '))
        index++;
    if (line[index] && line[index] != str){
        return -1;
    }
    index++;
    while (line[index] && ((line[index] >= 9 && line[index] <= 13) || line[index] == ' '))
        index++;
    while (line[index])
    {
        if (!std::isdigit(line[index]) && line[index] != '-' && line[index] != '+' && line[index] != '.')
            break ;
        value.push_back(line[index]);
        index++;
    }
    std::stringstream basic(value);
    basic >> value_nb;
    if (basic.fail() || (index < (int)line.size()))
        return -1;
    if (value_nb < 0 && !boleen)
        return -2;
    if (value_nb > 1000 && !boleen)
        return -3;
    return value_nb;
}


void BitcoinExchange::verifDate(int month, int day, int years) 
{
    
    switch (month) {
        case 1:  // Janvier
        case 3:  // Mars
        case 5:  // Mai
        case 7:  // Juillet
        case 8:  // Août
        case 10: // Octobre
        case 12: // Décembre
            if(day < 1 || day > 31) {
                std::cout << "Error of day" << std::endl;
            }
            break ;
        case 4:  // Avril
        case 6:  // Juin
        case 9:  // Septembre
        case 11: // Novembre
            if (day < 1 || day > 30){
                std::cout << "Error of day" << std::endl;
            }
            break ;
        case 2:  // Février
            if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0)) { // Année bissextile
                if (day < 1 || day > 29){
                std::cout << "Error of day" << std::endl;
                }
                break ;
            } else {
                if (day < 1 || day > 28){
                    std::cout << "Error of day" << std::endl;
                }
                break ;
        }
        default:
            break ;
    }
}


BitcoinExchange::~BitcoinExchange() 
{}

// Les autres fonctions restent inchangées, mais elles doivent être également modifiées de manière similaire.
