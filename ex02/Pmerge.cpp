/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:10:37 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/31 18:20:15 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"

Pmerge::Pmerge(int size, char **argv) : _size(size), _tab2(), _tab()
{
    this->_tab = create_tab(size, argv);
    detectPlage();
    this->_tab2 = calculate_cumulatif();
    right_list();
    std::cout << "size in here : " << this->_size << std::endl;
    // for (std::vector<int>::iterator it = this->_tab2.begin(); it != this->_tab2.end(); ++it)
    // {
    //     std::cout << "\ntab 2 : " << *it << std::endl;
    // }
    
}


void Pmerge::right_list() {
        this->_tab.assign(this->_tab2.size(), 0);
        for (std::vector<int>::iterator it = this->_tab2.begin(); it != this->_tab2.end(); it++) {
            this->_tab[*it] = 1;
        }
    }


std::vector<int>    create_tab(int argc, char **argv)
{
    std::vector<int>    tab;
    for (int i = 1; i < argc ; i++){
        std::cout << "\nargv[i] : " << argv[i] << std::endl;
        tab.push_back(atoi(argv[i]));
    }
    return tab;
}


std::vector<int>    Pmerge::calculate_cumulatif() {
        std::vector<int> new_tab((this->_max - this->_min) + 2);
        std::cout << "size of tab : " << (this->_max - this->_min) << std::endl;
        for (std::vector<int>::iterator it = this->_tab.begin(); it != this->_tab.end(); it++) {
            new_tab[*it] = *it;
        }
        for (std::vector<int>::iterator it = new_tab.begin(); it != new_tab.end(); it++)
        {
            std::cout << "num de it : " << *it << std::endl;
        }

        return new_tab;
    }

void    Pmerge::detectPlage(){
        std::vector<int>::iterator it;
    
    it = this->_tab.begin();
    this->_min = *it;
    this->_max = *it;
    for (it = this->_tab.begin(); it != this->_tab.end(); ++it){
        if (*it < this->_min)
            this->_min = *it;
        if (*it > this->_max)
            this->_max = *it;
    }
}

int verifArgc(int nb, char **num)
{
    for (int i = 1; i < nb; i++)
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

Pmerge::~Pmerge()
{}