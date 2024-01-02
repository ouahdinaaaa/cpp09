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

BitcoinExchange::BitcoinExchange(const std::string& filename) : _data(), _index(0) {
    parser_csv("data.csv");
    parser(filename);
}

void    BitcoinExchange::parser_csv(const std::string &filename) {
    const std::string filee = filename;
    std::ifstream file(filename.c_str());
    std::string date;
    std::string line;
    std::map<std::string, float>  Map_data;
    if (!file.is_open()){
        std::cout << "Error of file cannot open !!! " << std::endl;
    }
    getline(file, date);
    while (getline(file, date, ',')) {
        getline(file, line);
        Map_data[date] = atof(line.c_str());
    } this->_data = Map_data;
}

std::string BitcoinExchange::GetYears(const std::string &line){
    std::string Years = "";
    while (this->_index < (int)line.size()){
        if(line[this->_index] == '-' || line[this->_index] == '|')
            break ;
        Years.push_back(line[this->_index]);
        this->_index++;
    } return Years;
}

std::string BitcoinExchange::GetMonth(const std::string &line){
    std::string Month = "";
    if (line[this->_index] == '-')
        this->_index++;
    while (this->_index < (int)line.size()){
        if(line[this->_index] == '-' || line[this->_index] == '|')
            break ;
        Month.push_back(line[this->_index]);
        this->_index++;
    } return Month;
}

std::string BitcoinExchange::GetDay(const std::string &line){
    std::string Day = "";
    if (line[this->_index] == '-')
        this->_index++;
    while (this->_index < (int)line.size()){
        if(line[this->_index] == '|')
            break ;
        Day.push_back(line[this->_index]);
        this->_index++;
    }
    return Day;
}

std::string BitcoinExchange::GetValue(const std::string &line){
    std::string Value = "";
    if (line[this->_index] == '|')
        this->_index++;
    while (this->_index < (int)line.size() && line[this->_index] == ' ')
        this->_index++;
    while (this->_index < (int)line.size()){
        Value.push_back(line[this->_index]);
        this->_index++;
    }
    return Value;
}

void BitcoinExchange::parser(const std::string& filename) {
    const std::string file_str = filename;
    std::ifstream file(file_str.c_str());
    std::string lineYears = "";
    std::string lineMonth = "";
    std::string lineDay = "";
    std::string line = "";
    std::string value = "";

    if (!file.is_open()) {
        std::cout << "Error of file cannot open !!!" << std::endl;
        exit(1);
    } while (getline(file, line)) {
        this->_index = 0;
        lineYears = GetYears(line);
        lineMonth = GetMonth(line);
        lineDay = GetDay(line);
        value = GetValue(line);
        if (!VerifArg(lineYears, lineMonth, lineDay, value))// verif bien ecrit et bonne valeur 
            ParseOther(lineYears, lineMonth, lineDay, value);
    } file.close();
}

void    BitcoinExchange::ParseOther(std::string &years, std::string &month, std::string &day, std::string &value) {
    float   exchangeFloat = 0;
    std::string OldDate2 = "";
    std::string date = years + "-" + month + "-" + day;
    std::string date2 = AddDate2(atoi(years.c_str()), atoi(month.c_str()), atoi(day.c_str()));
    for (std::map<std::string, float>::iterator it = this->_data.begin() ; it !=  this->_data.end(); it++) {
        if (it->first < date){
            OldDate2 = it->first;
            exchangeFloat = atof(value.c_str()) * (it->second);
        }
    } std::cout << date2 << " => " << value << " = " << exchangeFloat << std::endl;
}

int    BitcoinExchange::VerifArg(std::string &years, std::string &month, std::string &day, std::string value){
    if (years[0] == '\n')
        return -1;
    for (size_t i = 0; i < years.size(); i++){
        if (std::isalpha(years[i]))
            return (DisplayBadInput(years, month, day, value));
    }
    for (size_t i = 0; i < month.size(); i++){
        if (std::isalpha(month[i]))
         return (DisplayBadInput(years, month, day, value));
        }
    for (size_t i = 0; i < day.size(); i++){
        if (std::isalpha(day[i]))
            return (DisplayBadInput(years, month, day, value));
    } for (size_t i = 0; i < value.size(); i++){
        if (std::isalpha(value[i]) || value.empty())
            return (DisplayBadInput(years, month, day, value));
    } if (atol(value.c_str()) > 1000){
        std::cout << "Error: too large a number." << std::endl;
        return -1;
    } else if (atol(value.c_str()) < 0){
        std::cout << "Error : not a positive number." << std::endl;
        return -1; 
    }
     if (verifDate(atoi(month.c_str()), atoi(day.c_str()), atoi(years.c_str())))
        return (DisplayBadInput(years, month, day, value));
    return 0;
}

std::string BitcoinExchange::AddDate2(int years, int month, int day) {
    std::stringstream ss;
    ss << years << "-" << month << "-" << day;
    return ss.str();
}

int BitcoinExchange::verifDate(int month, int day, int years) {
    if(month > 12 || years > 2024 || years < 0)
        return -1;
    switch (month) {
        case 1:  // Janvier
        case 3:  // Mars
        case 5:  // Mai
        case 7:  // Juillet
        case 8:  // Août
        case 10: // Octobre
        case 12: // Décembre
            if(day < 1 || day > 31)
                return -1;
        case 4:  // Avril
        case 6:  // Juin
        case 9:  // Septembre
        case 11: // Novembre
            if (day < 1 || day > 30)
                return -1;
        case 2:  // Février
            if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0)) { // Année bissextile
                if (day < 1 || day > 29)
                    return -1;
            } else {
                if (day < 1 || day > 28)
                    return -1;
        }
        default:
            break ;
    }
    return 0;
}


BitcoinExchange::~BitcoinExchange() 
{}

int    DisplayBadInput(std::string &Years, std::string &Month, std::string &Day, std::string &Value){
    std::cout << "Error : bad input => " << Years;
    if (Month.size() > 0)
        std::cout << "-" << Month;
    if (Day.size() > 0)
        std::cout << "-" << Day;
    if (Value.size() > 0)
        std::cout << "| " << Value;
    std::cout << std::endl;
    return -1;
}