/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange3.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:20:44 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/26 20:26:23 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE3_HPP
#define BITCOINEXCHANGE3_HPP

# include <string>
# include <vector>
#include <map>
#include <sstream>
# include <algorithm>
# include <iomanip>
# include <fstream>
# include <iostream>

struct Bitcoin_data
{
    std::string date;
    std::string error;
    std::string _date2;
    std::string _olDate2;
    float         value;
    int         good;
    int         day;
    int         month;
    int         years;
    float       exchangeRate;
};


class BitcoinExchange
{
    private :
    
    std::map<int, Bitcoin_data>   _data;
    int                        index;
    int                        index2;

    public :
    BitcoinExchange(const std::string &filename, int boleen);
    void    parser(const std::string &filename, int boleen);
    int     parserMonth(const std::string &line, int index);
    int     parserYears(const std::string &line, int index);
    int     parserDay(const std::string &line, int index);
    void    parse_line(const std::string &line, int boleen);
    float     parserValue(const std::string &line, int index, int boleen);
    void    parserDate();
    void    verifDate(Bitcoin_data &data);
    std::map<int, Bitcoin_data> &getData();
    ~BitcoinExchange();   
};

    // void    FindDate(BitcoinExchange &B1, BitcoinExchange &B2);
    void    FindDate(BitcoinExchange &B1,  BitcoinExchange &B2);
    void    FindDate2(Bitcoin_data &B1, BitcoinExchange &B2);
    void    printData(const Bitcoin_data &data);
    void    search_short(Bitcoin_data &B1, Bitcoin_data &B2, int boleen);


#endif