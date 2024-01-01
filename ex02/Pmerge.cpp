/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:10:37 by ayael-ou          #+#    #+#             */
/*   Updated: 2024/01/01 23:15:59 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"

Pmerge::Pmerge(int size, char **argv) : _tab2(), _tab()
{
    //time start
    this->_tab = create_list(size, argv);
    this->_tab = TriSpecial(this->_tab);
    /*
        List before // Afteeer
    */
    //time stop and affiche list ajouter container list pour liste non trie afficher before
    // 
    this->_tab2 = create_vector(size, argv);
    afficheVector();
    this->_tab2 = TriSpecial(this->_tab2);
    
}

std::vector<int>    Pmerge::create_vector(int argc, char **argv)
{
    std::vector<int>    tab;
    for (int i = 1; i < argc ; i++){
        tab.push_back(atoi(argv[i]));
    }
    return tab;
}

std::list<int>    Pmerge::create_list(int argc, char **argv)
{
    std::list<int>    tab;
    for (int i = 1; i < argc ; i++){
        tab.push_back(atoi(argv[i]));
    }
    return tab;
}

void    Pmerge::afficheList()
{
    std::cout << "\nNum List: ";
    for (std::list<int>::iterator it = this->_tab.begin(); it != this->_tab.end(); ++it){
        std::cout << " " << *it ;
    }
    std::cout << " " << std::endl;
    
}

void    Pmerge::afficheVector()
{
    std::cout << "\nNUm  Vector: ";
    for (std::vector<int>::iterator it = this->_tab2.begin(); it != this->_tab2.end(); ++it){
        std::cout << " " << *it;
    }
    std::cout << " " << std::endl;
    
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