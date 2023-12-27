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
#include <stack>
#include <deque>
#include <string>
#include <cmath>
#include <sstream>


class Rnp
{
private:
    std::deque<std::string> _pile;
    int            _index;

public:
    Rnp(const std::string &name);
    void    calculate();
    void    FirstInt(const std::string &name);
    void    Verif();
    ~Rnp();
};

std::string calculateNb(std::string nb1, std::string nb2, std::string op);

int RNP(const std::string& operation);

#endif