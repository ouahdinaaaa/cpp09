/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rnp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:44:30 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/25 22:44:30 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rnp.hpp"

// void print_mess(void)
// {
//     std::cout << "print message <<" << std::endl;
// }

int RNP(const std::string& operation) 
{
    std::stack<int> pile;
    std::string number;
    int i = 0;

    while (i < (int)operation.size()) {
        while (std::isspace(operation[i]))
            i++;

        if (std::isdigit(operation[i]) || (operation[i] == '-' && std::isdigit(operation[i + 1]))) {
            number = "";
            while (std::isdigit(operation[i]) || operation[i] == '-') {
                number += operation[i++];
            }
            pile.push(atoi(number.c_str()));
        } else if (operation[i] == '+' || operation[i] == '-' || operation[i] == '*' || operation[i] == '/') {
            if (pile.size() < 2) {
                std::cout << "Erreur : Expression invalide" << std::endl;
                return -1;
            }
            int operand2 = pile.top();
            pile.pop();
            int operand1 = pile.top();
            pile.pop();
            if (operation[i] == '+')
                pile.push(operand1 + operand2);
            else if (operation[i] == '-')
                pile.push(operand1 - operand2);
            else if (operation[i] == '*')
                pile.push(operand1 * operand2);
            else if (operation[i] == '/') {
                if (operand2 == 0) {
                    std::cout << "Erreur : Division par zéro" << std::endl;
                    return -1;
                }
                pile.push(operand1 / operand2);
            }
            i++;
        } else {
            std::cout << "Erreur : Caractère invalide" << std::endl;
            return -1;
        }
    }
    if (pile.size() != 1) {
        std::cout << "Erreur : Expression invalide" << std::endl;
        return -1;
    }
    return pile.top();
}
