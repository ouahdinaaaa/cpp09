/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rnp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:44:30 by ayael-ou          #+#    #+#             */
/*   Updated: 2024/01/03 16:54:38 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rnp.hpp"

Rnp::Rnp(const std::string &name) : _pile() , _index(0) {
    realSize(name);
    if (name.size() == 0)
        throw(ExceptionArg());
    while (_index < this->_size){
    FirstInt(name);
    Verif();
    calculate();
    }
    std::cout << "le resultat est : " << this->_pile[0] << std::endl;
}


void    Rnp::realSize(const std::string &line)
{
    std::string name = "";
    int size = ((int)line.size() - 1);
    while (size > 0 && line[size] == ' ')
        size--;
    this->_size = size;
    while (this->_index && line[this->_index] == ' ')
        this->_index++;
    
}


void    Rnp::FirstInt(const std::string &name) {
    std::string pile1;
    std::string s1;
    std::string s2;
    std::string s3;
    std::string s4;
    std::string s5;

    while (this->_index < (int)name.size() && this->_pile.size() < 2){
        if (this->_pile.size() > 0){
            s1 = this->_pile[0];
            this->_pile.pop_front();}
        else{
            while (this->_index < (int)name.size() && isspace(name[this->_index]))
                this->_index++;
            while (this->_index < (int)name.size() && !isspace(name[this->_index]))
                s1.push_back(name[this->_index++]);}
        while (this->_index < (int)name.size() && isspace(name[this->_index]))
            this->_index++;
        while (this->_index < (int)name.size() && !isspace(name[this->_index]))
            s2.push_back(name[this->_index++]);
        while (this->_index < (int)name.size() && isspace(name[this->_index]))
            this->_index++;
        while (this->_index < (int)name.size() && !isspace(name[this->_index]) && name[this->_index] != ' ')
            s3.push_back(name[this->_index++]);
        if (s3[0] != '*'  && s3[0] != '-' && s3[0] != '/' && s3[0] != '+') {
            while (this->_index < (int)name.size() && isspace(name[this->_index]))
                this->_index++;
            while (this->_index < (int)name.size() && !isspace(name[this->_index]) && name[this->_index] != ' ')
                s4.push_back(name[this->_index++]);
            if (s4[0] != '+' && s4[0] != '*' && s4[0] != '-' && s4[0] != '/')
                throw(ExceptionArg());
            else{
                s2 = calculateNb(s2, s3, s4);
                s3 = "";
            while (this->_index < (int)name.size() && isspace(name[this->_index]))
                this->_index++;
            while (this->_index < (int)name.size() && !isspace(name[this->_index]))
                s3.push_back(name[this->_index++]);
            if (s3.empty())
                throw(ExceptionArg());}
        } 
        this->_pile.push_back(s1);
        this->_pile.push_back(s2);
        this->_pile.push_back(s3);
        break ; }
}

std::string Rnp::calculateNb(std::string nb1, std::string nb2, std::string op) {
    int nb11 = atoi(nb1.c_str());
    int nb22 = atoi(nb2.c_str());
    
    std::ostringstream   str;
    std::ostringstream   str1;
    str1 << nb22;
    str << nb11;
    if (((str1.str()).size() != nb1.size()) || ((str.str()).size() != nb2.size()))
        throw(ExceptionArg());
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
    if (_pile.size() < 3)
        throw(ExceptionArg());
    std::string nb1 = _pile[0];
    std::string nb2 = _pile[1];
    std::string ope = _pile[2];
    if ((ope[0] != '+' && ope[0] != '-' && ope[0] != '/' && ope[0] != '*') || ope.size() > 1)
        throw(ExceptionOperator());
}

void    Rnp::calculate() {
    if (this->_pile.size() < 3)
        throw(ExceptionInsufficense());
    int nb1 = atoi(_pile[0].c_str());
    int nb2 = atoi(_pile[1].c_str());

    std::ostringstream   str;
    std::ostringstream   str1;
    str1 << nb1;
    str << nb2;
    if ((_pile[0].size() != (str1.str()).size()) || ((str.str()).size() != _pile[1].size()))
        throw(ExceptionArg());
    std::string op = _pile[2];
    std::ostringstream   basic;
    int res = 0;
    if (op[0] == '+')
        res = nb1 + nb2;
    else if (op[0] == '-')
        res = nb1 - nb2;
    else if (op[0] == '/' && nb2 != 0)
        res = nb1 / nb2;
    else if (op[0] == '/' && nb2 == 0)
        res = 0;
    else if (op[0] == '*')
        res = nb1 * nb2;
    basic << res;
    _pile.pop_front();
    _pile.pop_front();
    _pile.pop_front();
    _pile.push_front(basic.str());
}

Rnp::~Rnp() {}
