/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TriSpecial.List.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 21:35:06 by ayael-ou          #+#    #+#             */
/*   Updated: 2024/01/01 21:35:06 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <algorithm>


std::list<int> TriSpecial(std::list<int> &X) 
{
    int n = X.size();

    std::list<int> ElementsPlusGrand;
    if (n <= 1) {
        return X;
    }

    int m = n / 2;

    std::list<std::pair<int, int>> pairs;
    auto it = X.begin();
    for (int i = 0; i < m; i += 2) {
        if (std::next(it, 1) != X.end()) {
            pairs.push_back(std::make_pair(*it, *(std::next(it, 1))));

            // Tri et récupération des éléments plus grands
            if (pairs.back().first > pairs.back().second) {
                std::swap(pairs.back().first, pairs.back().second);
                ElementsPlusGrand.push_back(pairs.back().first);
            } else {
                ElementsPlusGrand.push_back(pairs.back().second);
            }
        }
        std::advance(it, 2);
    }
    ElementsPlusGrand = (TriSpecial(ElementsPlusGrand));
    for (auto &pair : pairs) {
        if (pair.second < pair.first) {
            std::swap(pair.first, pair.second);
        }
    }

    std::list<int> resultat;
    for (const auto& pair : pairs) {
    auto idx = std::lower_bound(resultat.begin(), resultat.end(), pair.first);
    resultat.insert(idx, pair.first);
    idx = std::lower_bound(resultat.begin(), resultat.end(), pair.second);
    resultat.insert(idx, pair.second);
}
    for (auto it = next(X.begin(), m); it != X.end(); ++it) {
        auto idx = lower_bound(resultat.begin(), resultat.end(), *it);
        resultat.insert(idx, *it);
    }
    return resultat;
}

int main() {
    // std::list<int> Desorder = {45, 1, 4, -6, 5, 2, 9, 11, 3, -4, -2, 12};
    std::list<int> Desorder = {1203, 1345, 1732, 2785, 2900, 2822, 2745, 2668, 2591, 2514, 2437, 2360, 2283, 2206, 2129, 2052, 1975, 1898, 1821, 1744, 1667, 1590, 1513, 1436, 1359, 1282, 1205, 1128, 1051, 974, 897, 820, 743, 666, 589, 512, 435, 358, 281, 204, 127, 50, -27, -104, -181, -258, -335, -412, -489, -566, -643, -720, -797, -874, -951, -1028, -1105, -1182, -1259, -1336, -1413, -1490, -1567, -1644, -1721, -1798, -1875, -1952, -2029, -2106, -2183, -2260, -2337, -2414, -2491, -2568, -2645, -2722, -2799};

    std::list<int> Tried = TriSpecial(Desorder);

    std::cout << "\nListe triée jusqu'à la moitié : ";
    for (std::list<int>::iterator it = Tried.begin(); it != Tried.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
