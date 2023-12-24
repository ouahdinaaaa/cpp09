/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:56:39 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/24 20:00:21 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2){
        std::cout << "Error arg !!" << std::endl;
        return 1;
    }
    BitcoinExchange Bitcoin(argv[1]);
    std::cout << "------------------ FINISH -------------------" << std::endl;
}