/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rnp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:44:30 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/27 11:52:59 by ayael-ou         ###   ########.fr       */
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

void    Rnp::FirstInt(const std::string &name)
{
    std::string pile1;
    std::string s1;
    std::string s2;
    std::string s3;
    std::string s4;
    std::string s5;

    while (this->_index < (int)name.size() && this->_pile.size() < 2){
        // std::cout << "open in " << std::endl;
        if (this->_pile.size() > 0){
            s1 = this->_pile[0];
            this->_pile.pop_front();
        }
        else
        {
            while (this->_index < (int)name.size() && isspace(name[this->_index]))
                this->_index++;
            while (this->_index < (int)name.size() && !isspace(name[this->_index]))
                s1.push_back(name[this->_index++]);
        }
        while (this->_index < (int)name.size() && isspace(name[this->_index]))
            this->_index++;
        while (this->_index < (int)name.size() && !isspace(name[this->_index]))
            s2.push_back(name[this->_index++]);
        while (this->_index < (int)name.size() && isspace(name[this->_index]))
            this->_index++;
        while (this->_index < (int)name.size() && !isspace(name[this->_index]))
            s3.push_back(name[this->_index++]);
        // std::cout << "nb3 : " << s3 << std::endl;
        if (s3[0] != '*'  && s3[0] != '-' && s3[0] != '/' && s3[0] != '+')
        {
            // std::cout << "open in here " << std::endl;
            while (this->_index < (int)name.size() && isspace(name[this->_index]))
                this->_index++;
            while (this->_index < (int)name.size() && !isspace(name[this->_index]))
                s4.push_back(name[this->_index++]);
            if (s4[0] != '+' && s4[0] != '*' && s4[0] != '-' && s4[0] != '/')
            {
                std::cout << "Error of caractere" << std::endl;
                exit(1); //Reflechir a faire un try/catch pour plus de propretee
            }
            else
            {
                s2 = calculateNb(s2, s3, s4);
                s3 = "";
            while (this->_index < (int)name.size() && isspace(name[this->_index]))
                this->_index++;
            while (this->_index < (int)name.size() && !isspace(name[this->_index]))
                s3.push_back(name[this->_index++]);
            if (s3.empty()){
                std::cout << "Error in arg !!!" << std::endl; 
                return ;
                // std::cout << "s1 : " << s1 << "|| s2 : " << s2 << "|| s3 : " << s3 << std::endl;
            }
            }
        }
        this->_pile.push_back(s1);
        this->_pile.push_back(s2);
        this->_pile.push_back(s3);
        break ;
    }
}

std::string calculateNb(std::string nb1, std::string nb2, std::string op)
{
    int nb11 = atoi(nb1.c_str());
    int nb22 = atoi(nb2.c_str());
    std::ostringstream   basic;
    int res;

    if (op[0] == '+')
        res = nb11 + nb22;
    else if (op[0] == '-')
        res = nb11 - nb22;
    else if (op[0] == '/')
        res = nb11 / nb22;
    else if (op[0] == '*')
        res = nb11 * nb22;
    else
        res = 0;
    basic << res;
    return (basic.str());
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
    if (ope[0] != '+' && ope[0] != '-' && ope[0] != '/' && ope[0] != '*') {
        std::cout << "Error of operator: [" << ope << "]" << std::endl;
        std::cout << "nb1 [" << nb1 << "] !!!" << std::endl;
        std::cout << "nb2 [" << nb2 << "] !!!" << std::endl;
        return ;
    }
    // if (!std::isdigit(nb1[0]) || !std::isdigit(nb2[0]))
    //     std::cout << "Error: Operands must be numbers." << std::endl;
}

void    Rnp::calculate() 
{
    // std::cout << "size of : " << this->_pile.size() << std::endl;
    if (this->_pile.size() < 3) {
        std::cout << "Insufficient elements for calculation." << std::endl;
        return;
    }
    int nb1 = atoi(_pile[0].c_str());
    int nb2 = atoi(_pile[1].c_str());
    std::string op = _pile[2];
    std::ostringstream   basic;
    int res = 0;
    if (op[0] == '+')
        res = nb1 + nb2;
    else if (op[0] == '-')
        res = nb1 - nb2;
    else if (op[0] == '/')
        res = nb1 / nb2;
    else if (op[0] == '*')
        res = nb1 * nb2;
    basic << res;
    _pile.pop_front();
    _pile.pop_front();
    _pile.pop_front();
    _pile.push_front(basic.str());
}


Rnp::~Rnp()
{}



/* ------------------------------PARSING ---------------------
            doit revoir le delire des caractere verifier chaque string ne doit pas contenir de lettre
*/