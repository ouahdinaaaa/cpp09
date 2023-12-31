/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TriSpecial.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:05:18 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/31 16:14:32 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm> 

std::vector<int> TriSpecial(std::vector<int>& X) {
    int n = X.size();

    std::vector<int> ElementsPlusGrand;
    std::vector<std::pair<int, int>> pairs;
    if (n == 1) {
        return X;
    }

    int m = n / 2;

    std::cout << "*--------------------CALLED ---------------------*" << std::endl;
    for (int i = 0; i < m; i++) {
        pairs.push_back(std::make_pair(X[2 * i], X[2 * i + 1]));
        std::cout << "\npairs  i : first "  << pairs[i].first  << " ||| pairs  i : second : " << pairs[i].second  << std::endl;
    }
    
    
    for (std::pair<int, int>& pair : pairs) {
        if (pair.first < pair.second) {
            ElementsPlusGrand.push_back(pair.first);
        } else {
            ElementsPlusGrand.push_back(pair.second);
        }
    }

    ElementsPlusGrand = TriSpecial(ElementsPlusGrand);

    std::vector<int> resultat;

    for (int i = 0; i < m; ++i) {
        std::cout << "\npair i : " << pairs[i].first;
        resultat.push_back(pairs[i].first);
    }

    // Ajouter les éléments d'ElementsPlusGrand à la bonne position dans resultat
    for (int i = 0; i < (int)ElementsPlusGrand.size(); ++i) {
        int idx = std::upper_bound(resultat.begin(), resultat.end(), ElementsPlusGrand[i]) - resultat.begin();
        resultat.insert(resultat.begin() + idx, ElementsPlusGrand[i]);
    }

    return resultat;
}


int main() {
    std::vector<int> Desorder = {3, 1, 4, 2, 5, 6,};

    std::vector<int> Tried = TriSpecial(Desorder);

    // Affichage des éléments triés
    std::cout << "Liste triée : ";
    for (std::vector<int>::iterator it = Tried.begin(); it != Tried.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
