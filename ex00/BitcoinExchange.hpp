/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:26:30 by ayael-ou          #+#    #+#             */
/*   Updated: 2024/01/02 18:42:29 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <string>
# include <vector>
#include <map>
#include <iterator>
#include <sstream>
# include <algorithm>
# include <iomanip>
# include <fstream>
# include <iostream>

class BitcoinExchange
{
    private :
    
    std::map<std::string, float>   _data;
    int                            _index;

    public :
    int            verifDate(int month, int day, int years);
    int            VerifArg(std::string &years, std::string &month, std::string &day, std::string value);
    void           print_data();
    void           parser(const std::string &filename);
    void           parser_csv(const std::string &filename);
    void           ParseOther(std::string &years, std::string &month, std::string &day, std::string &value);
    std::string    GetDay(const std::string &line);
    std::string    GetYears(const std::string &line);
    std::string    GetMonth(const std::string &line);
    std::string    GetValue(const std::string &line);
    std::string    AddDate2(int years, int month, int day);
    ~BitcoinExchange();   
    BitcoinExchange(const std::string &filename);
};

int    DisplayBadInput(std::string &Years, std::string &Month, std::string &Day, std::string &Value);

#endif