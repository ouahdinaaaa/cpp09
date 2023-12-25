/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:29:44 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/25 20:34:36 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filename, int boleen) : _data()
{
    parser(filename, boleen);
    parserDate();
}

BitcoinExchange::~BitcoinExchange()
{}


void    BitcoinExchange::parser(const std::string &filename, int boleen)
{
    const std::string file_str = filename;
    std::ifstream   file(file_str.c_str());
    std::string     line;
    int             boucle;
    
    boucle = boleen;
    if (!file.is_open()){
        std::cout << "Error of file cannot open !!!" << std::endl;
        exit(1);
    }
    while (std::getline(file, line)){
        if (!line.empty() && --boucle < 0){
            parse_line(line, boleen);
        }
    }
    file.close();
}


void    BitcoinExchange::parse_line(const std::string &line, int boleen)
{
    
    Bitcoin_data data;

    data.years = parserYears(line, boleen);
    data.month = parserMonth(line, this->index);
    data.day = parserDay(line, this->index);
    data.value = parserValue(line, this->index, boleen);
    data.date = line;
    data.old_day = 1000;
    data.old_month = 1000;
    data.old_years = 1000;
    data.good = 0;
    if (data.day == -1 || data.month == -1 || data.years  == -1){
        data.good = 1;
        data.error = "bad input -> " + line;
    }
    if (data.value == -2){
        data.good = 1;
        data.error = "Error : Number is not positive";
    }
    if (data.value == -3){
        data.good = 1;
        data.error = "Error : Number too large a number";
    }
    std::cout << "value in parse line : " << std::fixed << std::setprecision(1) << data.value << std::endl;
    this->_data.push_back(data);
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

int     BitcoinExchange::parserValue(const std::string &line, int index, int boleen)
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


void BitcoinExchange::verifDate(Bitcoin_data &data) 
{
    
    switch (data.month) {
        std::cout << "Value : " << std::fixed << std::setprecision(1) << data.value << std::endl;
        case 1:  // Janvier
        case 3:  // Mars
        case 5:  // Mai
        case 7:  // Juillet
        case 8:  // Août
        case 10: // Octobre
        case 12: // Décembre
            if(data.day < 1 || data.day > 31) {
                data.good = 1;
            }
            break ;
        case 4:  // Avril
        case 6:  // Juin
        case 9:  // Septembre
        case 11: // Novembre
            if (data.day < 1 || data.day > 30){
                data.good = 1;
            }
            break ;
        case 2:  // Février
            if ((data.years % 4 == 0 && data.years % 100 != 0) || (data.years % 400 == 0)) { // Année bissextile
                if (data.day < 1 || data.day > 29){
                    data.good = 1;
                }
                break ;
            } else {
                if (data.day < 1 || data.day > 28){
                    data.good = 1;
                }
                break ;
        }
        default:
            break ;
    }
}


void    BitcoinExchange::parserDate()
{
    std::vector<Bitcoin_data>::iterator it;
    for (it = this->_data.begin(); it < this->_data.end(); it++){
        verifDate(*it);
    }
}

void    printData(const Bitcoin_data &data){
    if (!data.good)
        std::cout << data.years << "-" << data.month << "-" << data.day << " => " << std::fixed << std::setprecision(1) << data.value << " = " << data.exchangeRate << std::endl;
    else
        std::cout << data.error << std::endl;
}

void    FindDate(BitcoinExchange B1,  BitcoinExchange B2)
{
    std::vector<Bitcoin_data>   Bit1 = B1.getData();
    

    std::vector<Bitcoin_data>::iterator it;
    for (it = Bit1.begin(); it < Bit1.end(); it++){
        FindDate2(*it, B2);
    }
    
}

void    FindDate2(Bitcoin_data B1, BitcoinExchange B2)
{
    std::vector<Bitcoin_data>   Bit2 = B2.getData();

    std::vector<Bitcoin_data>::iterator it;
    int index = 0;
    for (it = Bit2.begin(); it < Bit2.end(); it++){
        search_short(B1, *it, index);
        index++;
    }
    
}


void    search_short(Bitcoin_data B1, Bitcoin_data B2, int boleen)
{
    int Years1 = 365 * B1.years;
    int Years2 = 365 * B2.years;
    int Month1 = 31 * B1.month;
    int Month2 = 31 * B2.month;
    int DayB2 = B2.day;
    int DayB1 = B1.day;
    int DayB2_old = (365 * B1.old_years) + (31 * B1.old_month) + (B1.old_day);
    int total1 = Years1 + Month1 + DayB1;
    int total2 = Years2 + Month2 + DayB2;

    if (total1 > total2 && !boleen && !B1.good)
    {
        B1.exchangeRate = B1.value * B2.value;
        B1.old_day = B2.day;
        B1.old_month = B2.month;
        B1.old_years = B2.years;
    }
    else if (total2 < DayB2_old && total2 < total1 && boleen && !B1.good){
        B1.exchangeRate = B1.value * B2.value;
        // std::cout << "exchange value : "<< std::fixed << std::setprecision(1) << B1.exchangeRate << std::endl;
        B1.old_day = B2.day;
        B1.old_month = B2.month;
        B1.old_years = B2.years;
    }
}