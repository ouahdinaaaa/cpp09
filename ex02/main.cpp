/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:10:52 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/31 14:19:10 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"

int main(int argc, char **argv)
{
    if (argc < 2){
        std::cout << "Error you forget parametre " << std::endl;
        return 1;}
    else if (verifArgc(argc, argv)){
        std::cout << "Error in your list !!!" << std::endl;
        return 1;}

    Pmerge  list(argc, argv);
    
    return 0;
}