/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:44:55 by ayael-ou          #+#    #+#             */
/*   Updated: 2024/01/02 16:06:00 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <string>
#include <ctime>
#include <chrono>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

class Pmerge
{
    private:
    std::vector<int>    _tab2;
    std::list<int>      _tab;
    
    public:
    
    Pmerge(int size, char **argv);
    ~Pmerge();
    
    void   detectPlage();
    std::list<int>    TriSpecial(std::list<int> &X);
    std::vector<int>    create_vector(int argc, char **argv);
    std::list<int>    create_list(int argc, char **argv);
    std::vector<int>  TriSpecial(std::vector<int> &X);
    void              afficheList(const std::string &phrase);
    void              afficheVector(const std::string &phrase);
};

int    verifArg(const std::string &num);
int    verifArgc(int nb, char **num);

#endif