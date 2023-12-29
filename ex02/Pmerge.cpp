/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:10:37 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/29 16:08:58 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"

int verifArgc(int nb, char **num)
{
    for (int i = 0; i < nb; i++)
    {
        if (verifArg(num[i]))
            return 1;
    }
    return 0;
}

int    verifArg(const std::string &num)
{
    for (int i = 0; i < (int)num.size(); i++)
    {
        if (!isdigit(num[i]))
            return 1;
    }
    return 0;
}

std::vector<int>    create_tab(int argc, char **argv)
{
    
}

Pmerge::Pmerge(int size, char **argv) : _size(size), _tab(), _tab2()
{
    this->_tab = create_tab(size, argv);
}

std::vector<int>    create_tab(int argc, char **argv)
{
    std::vector<int>    tab;
    for (int i = 0; i < argc - 1; i++){
        tab.push_back(atoi(argv[i]));
    }
    return tab;
}

void    Pmerge::detectPlage(){
        std::vector<int>::iterator it;
    
    this->_min = *it;
    this->_max = *it;
    it = this->_tab.begin();
    for (it = this->_tab.begin(); it != this->_tab.end(); ++it){
        if (*it < this->_min)
            this->_min = *it;
        if (*it > this->_max)
            this->_max = *it;
    }
}

Pmerge::~Pmerge()
{}