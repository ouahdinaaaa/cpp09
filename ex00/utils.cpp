/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:19:32 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/28 12:23:32 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void    Bitcoinparserline(const std::string &line, int index)
{
    int value = parserValue(line, index, 0);
    int Years;
    int Date;   
    int Day;
    
    
}