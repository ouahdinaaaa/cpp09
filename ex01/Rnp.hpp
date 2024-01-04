/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rnp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:38:10 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/25 22:38:10 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP

#include <iostream>
#include <iomanip>
#include <stack>
#include <deque>
#include <string>
#include <cmath>
#include <sstream>
#include <exception>


class Rpn
{
private:
    std::deque<double> _pile;
    int            _index;
    int             _size;

public:
    Rpn();
    Rpn(const Rpn &objs);
    Rpn &operator=(const Rpn &objs);
    void       parse(const std::string &expresion);
    // void    calculate();
    // void    realSize(const std::string &line);
    // void    FirstInt(const std::string &name);
    ~Rpn();

    class ExceptionArg : public std::exception
    {
        public :
        const char *what() const throw()
        {
            return ("Error on your list\n");
        }
    };

    class ExceptionOperator : public std::exception
    {
        public : 
        const char *what() const throw()
        {
            return ("Error of operator\n");
        }
    };

    class ExceptionInsufficense : public std::exception
    {
        public :
        const char *what() const throw()
        {
            return ("Insufficent element for calculation\n");
        }
    };
    std::string calculateNb(std::string nb1, std::string nb2, std::string op);
};



#endif