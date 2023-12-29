/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:44:55 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/29 16:05:42 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

class Pmerge
{
    private:
    int                 _size;
    std::vector<int>    _tab2;
    std::vector<int>    _tab;
    int                 _min;
    int                 _max;
    
    public:
    
    Pmerge(int size, char **argv);
    ~Pmerge();
    
    void   detectPlage();
};

int    verifArg(const std::string &num);
int    verifArgc(int nb, char **num);
std::vector<int>    create_tab(int argc, char **argv);

#endif