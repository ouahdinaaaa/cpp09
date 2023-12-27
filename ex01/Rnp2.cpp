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

Rnp::Rnp(const std::string &name) : _pile() , _index(0)
{
    while (_index < (int)name.size()){
    FirstInt(name);
    Verif();
    calculate();
    }
    std::cout << "le resultat est : " << this->_pile[0] << std::endl;
}

void Rnp::FirstInt(const std::string &name) 
{
        int nb1, nb2;
        char op;
        std::string token;
        
        while (_pile.size() < 3 && this->_index < (int)name.size()) 
        {
            while (this->_index < (int)name.size() && isspace(name[this->_index]))
                this->_index++;
            // std::cout << "name[index] : {" << (int)name[this->_index] << std::endl; // on est sur du 8
            if (_pile.size() != 0)
                token = _pile[0];
            else 
            {
                while (this->_index < (int)name.size() && isdigit(name[this->_index])){
                    token.push_back(name[this->_index]);
                    this->_index++;
                }
                // std::cout << "token nb : " << token << std::endl;
                // nb1 = atoi(token.c_str());
                this->_pile.push_front(token);
            }
            token = "";
            while (this->_index < (int)name.size() && !isspace(name[this->_index]) && !isdigit(name[this->_index])) 
            {
                token.push_back(name[this->_index]);
                this->_index++;
            }
            if (!token.empty()) {
                if (isdigit(token[0])) {
                    nb2 = atoi(token.c_str());
                    this->_pile.push_front(std::to_string(nb2));
                } else {
                    op = token[0];
                    this->_pile.push_front(std::string(1, op));
                }
            }
            // this->_index++;
            // std::cout << "you hou : index : " << this->_index << std::endl;
        }
    }


void    Rnp::Verif() 
{
    if (_pile.size() < 3) {
        std::cout << "Not enough elements for operation." << std::endl;
        return;
    }
    std::string nb1 = _pile[0];
    std::string nb2 = _pile[1];
    std::string ope = _pile[2];
    if (ope[0] != '+' && ope[0] != '-' && ope[0] != '/' && ope[0] != '*')
        std::cout << "Error of operator: " << ope << std::endl;
    if (!std::isdigit(nb1[0]) || !std::isdigit(nb2[0]))
        std::cout << "Error: Operands must be numbers." << std::endl;
}

void    Rnp::calculate() 
{
    if (_pile.size() < 3) {
        std::cout << "Insufficient elements for calculation." << std::endl;
        return;
    }
    int nb1 = atoi(_pile[0].c_str());
    int nb2 = atoi(_pile[1].c_str());
    std::string op = _pile[2];

    int res = 0;
    if (op[0] == '+')
        res = nb1 + nb2;
    else if (op[0] == '-')
        res = nb1 - nb2;
    else if (op[0] == '/')
        res = nb1 / nb2;
    else if (op[0] == '*')
        res = nb1 * nb2;

    _pile.pop_front();
    _pile.pop_front();
    _pile.pop_front();

    _pile.push_front(std::to_string(res));
}

Rnp::~Rnp()
{}