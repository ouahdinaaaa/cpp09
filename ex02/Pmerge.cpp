/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:10:37 by ayael-ou          #+#    #+#             */
/*   Updated: 2024/01/02 16:41:46 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"

Pmerge::Pmerge(int size, char **argv) : _tab2(size + 1), _tab(size + 1)
{
    //time start
    std::clock_t c_start = std::clock();
    this->_tab = create_list(size, argv);
    afficheList("Before : ");
    this->_tab = TriSpecial(this->_tab);
    c_start = std::clock() - c_start;
    /*
        List before // Afteeer
    */
    //time stop and affiche list ajouter container list pour liste non trie afficher before
    std::clock_t c_vec= std::clock();
    this->_tab2 = create_vector(size, argv);
    // afficheVector("Before : ");
    this->_tab2 = TriSpecial(this->_tab2);
    c_vec = std::clock() - c_vec;
    afficheVector("After : Vector Tried : ");
    afficheList("After   : List Tried : ");
    std::cout << "\nTime to process a range of 3000 element with std::Vector<int> : " << c_vec/static_cast<double>(CLOCKS_PER_SEC / 1000) << "seconde" << std::endl;
    std::cout << "Time to process a range of 3000 element with std::List<int> : " << c_start/static_cast<double>(CLOCKS_PER_SEC / 1000) << "seconde" << std::endl;
    
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

void    Pmerge::afficheList(const std::string &phrase)
{
    std::cout << "\n" << phrase;
    for (std::list<int>::iterator it = this->_tab.begin(); it != this->_tab.end(); ++it){
        std::cout << " " << *it ;
    }
    std::cout << " " << std::endl;
    
}

void    Pmerge::afficheVector(const std::string &phrase)
{
    std::cout << "\n" << phrase;
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