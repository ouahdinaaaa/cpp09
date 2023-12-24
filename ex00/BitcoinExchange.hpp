/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:20:44 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/24 20:10:05 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <string>
# include <vector>
# include <algorithm>
# include <iomanip>
# include <fstream>
# include <iostream>

struct Bitcoin_data
{
    std::string date;
    int         value;
    int         day;
    int        month;
    int         years;
};


class BitcoinExchange
{
    private :
    
    std::vector<Bitcoin_data>   data;
    int                        index;

    public :
    BitcoinExchange(const std::string &filename);
    void    parser(const std::string &filename);
    int     parserMonth(const std::string &line, int index);
    int     parserYears(const std::string &line, int index);
    int     parserDay(const std::string &line, int index);
    void    parse_line(const std::string &line);
    int     parserValue(const std::string &line, int index);
    ~BitcoinExchange();   
};

#endif