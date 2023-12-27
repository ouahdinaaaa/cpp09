/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:26:30 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/27 18:45:37 by ayael-ou         ###   ########.fr       */
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
    
    std::map<std::string, int>   _data;
    int                        index;
    // int                        index2;
    // int                        date2;   

    public :
    BitcoinExchange(const std::string &filename);
    void    parser(const std::string &filename, int boleen);
    int     parserMonth(const std::string &line, int index);
    int     parserYears(const std::string &line, int index);
    int     parserDay(const std::string &line, int index);
    void    parse_line(const std::string &line, int boleen);
    float     parserValue(const std::string &line, int index, int boleen);
    void    verifDate(int month, int day, int yeras);
    void    parser_csv(const std::string &filename);
    ~BitcoinExchange();   
};

#endif