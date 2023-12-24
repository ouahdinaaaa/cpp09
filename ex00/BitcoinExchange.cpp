/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:29:44 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/24 20:27:22 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
    parser(filename);
}

BitcoinExchange::~BitcoinExchange()
{}


void    BitcoinExchange::parser(const std::string &filename)
{
    const std::string file_str = filename;
    std::ifstream   file(file_str.c_str());
    std::string     line;
    
    if (!file.is_open()){
        std::cout << "Error of file cannot open !!!" << std::endl;
        exit(1);
    }
    while (std::getline(file, line)){
        if (!line.empty()){
            parse_line(line);
        }
    }
    file.close();
}

void    BitcoinExchange::parse_line(const std::string &line)
{
    
    Bitcoin_data data;

    data.years = parserYears(line, 0);
    data.month = parserMonth(line, this->index);
    data.day = parserDay(line, this->index);
    data.value = parserValue(line, this->index);
    data.date = line;
    this->data.push_back(data);
}

int    BitcoinExchange::parserYears(const std::string &line, int index)
{
    std::string years;
    int         years_nb;

    while (line[index] && (line[index] >= 9 && line[index] <= 13))
        index++;
    while (line[index]){
        if (!std::isdigit(line[index]))
            break ;
        years.push_back(line[index]);
        index++;
    }
    years_nb = std::atoi(years.c_str());
    if (years_nb < 0 || years_nb > 2024){
        std::cout << "1.bad input -> " << line << std::endl; // voir a remplacer par try/catch
        exit(0);
    }
    this->index = index;
    return years_nb;
}

int    BitcoinExchange::parserMonth(const std::string &line, int index)
{
    std::string     month;
    int             month_nb;
    
    if (!line[index] || !line[index + 1]|| line[index] != '-'){
        std::cout << "2.bad input -> " << line << std::endl;
        exit(0);
    }
    index++;
    while (line[index] && (line[index] >= 9 && line[index] <= 13))
        index++;
    while (line[index]){
        if (!std::isdigit(line[index]))
            break ;
        month.push_back(line[index]);
        index++;
    }
    month_nb = std::atoi(month.c_str());
    if (month_nb < 1 || month_nb > 12){
        std::cout << "bad input -> " << line << std::endl;
        exit(0);
    }
    this->index = index;
    return month_nb;
}

int    BitcoinExchange::parserDay(const std::string &line, int index)
{
    std::string day;
    int         day_nb;

    if (!line[index] || line[index] != '-' || !line[index + 1]){
        std::cout << "4.bad input -> " << line << std::endl;
        exit(0);
    }
    index++;
    while (line[index] && (line[index] >= 9 && line[index] <= 13))
        index++;
    while (line[index]){
        if (!std::isdigit(line[index]))
            break ;
        day.push_back(line[index]);
        index++;
    }
    day_nb = std::atoi(day.c_str());
    if (day_nb < 1 || day_nb > 30){
        std::cout << "bad input " << line << std::endl;
        exit(0);
    }
    this->index = index;
    return day_nb;   
}

int     BitcoinExchange::parserValue(const std::string &line, int index)
{
    std::string value;
    int value_nb;

    if (!(line[index] >= 9 && line[index] <= 13) || line[index] != '|'){
        std::cout << "bad input " << line << std::endl;
        exit(0);
    }
    while (line[index] && (line[index] >= 9 && line[index] <= 13))
        index++;
    if (line[index] && line[index] != '|'){
        std::cout << "2bad input " << line << std::endl;
        exit(0);
    }
    while (line[index])
    {
        if (!std::isdigit(line[index]))
            break ;
        value.push_back(line[index]);
        index++;
    }
    value_nb = std::atoi(value.c_str());
    if (value_nb < 0 || value_nb > 1000){
        std::cout << "8.bad input " << line << std::endl;
        exit(0);
    }
    return value_nb;
}

/*              EXEMPLE OF LINE
    2011-01-03 | 3
*/