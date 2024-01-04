/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rnp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:08:53 by ayael-ou          #+#    #+#             */
/*   Updated: 2024/01/04 16:27:45 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rnp.hpp"

Rpn::Rpn() {}

Rpn::Rpn(const Rpn &objs)
{
    *this = objs;
}

Rpn& Rpn::operator=(const Rpn &objs)
{
    this->_pile = objs._pile;
    return (*this);
}

Rpn::~Rpn() {}

void    Rpn::parse(const std::string &expression)
{
    char c;
    
    for(size_t i = 0; i < expression.length(); i++)
    {
        c = expression[i];
        if (c == ' ')
        {
            continue ;
        }
        else if (isdigit(c))
        {
            int number = c - '0';
            this->_pile.push_front(number);
        }
        else if (c == '+' && this->_pile.size() >= 2)
        {
            double a = this->_pile[0];
            this->_pile.pop_front();
            double b = this->_pile[0];
            this->_pile.pop_front();
            this->_pile.push_front(a + b);
        }
        else if (c == '-' && this->_pile.size() >= 2)
        {
            double a = this->_pile[0];
            this->_pile.pop_front();
            double b = this->_pile[0];
            this->_pile.pop_front();
            this->_pile.push_front(b - a);
        }
        else if (c == '*' && this->_pile.size() >= 2)
        {
            double a = this->_pile[0];
            this->_pile.pop_front();
            double b = this->_pile[0];
            this->_pile.pop_front();
            this->_pile.push_front(a * b);
        }
        else if (c == '/' && this->_pile.size() >= 2)
        {
            double a = this->_pile[0];
            this->_pile.pop_front();
            double b = this->_pile[0];
            this->_pile.pop_front();
            this->_pile.push_front(b / a);
        }
        else
            throw (ExceptionOperator());
    }
    if (this->_pile.size() == 1)
    {
        std::cout << "Le resultat est : " << this->_pile[0] << std::endl;
        this->_pile.pop_front();
    }
    else
        throw(ExceptionArg());
}