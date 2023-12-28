/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:26:30 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/28 14:40:24 by ayael-ou         ###   ########.fr       */
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

    public :
    BitcoinExchange(const std::string &filename);
    void    parser(const std::string &filename);
    int    verifDate(int month, int day, int years);
    void    parser_csv(const std::string &filename);
    int     VerifArg(std::string &years, std::string &month, std::string &day, std::string value);
    void    print_data();
    std::string AddDate2(int years, int month, int day);
    void    ParseOther(std::string &years, std::string &month, std::string &day, std::string &value);
    ~BitcoinExchange();   
};

#endif