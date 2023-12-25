/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:56:39 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/25 23:14:40 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    BitcoinExchange Bitcoin(argv[1], 0);
    BitcoinExchange Bitcoin2("data.csv", 1);

    // FindDate(Bitcoin, Bitcoin2);
    
    // std::vector<Bitcoin_data> Bitcoin3 = Bitcoin.getData();
    // std::vector<Bitcoin_data>::iterator it;
    // for (it = Bitcoin3.begin(); it < Bitcoin3.end() ; it++){
    //     printData(*it);
    }
    //fonction pour recuperer short date entre deux.
    //Fonction calcule taux change.
// }