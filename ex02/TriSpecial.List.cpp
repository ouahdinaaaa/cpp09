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

#include "Pmerge.hpp"

std::list<int> Pmerge::TriSpecial(std::list<int> &X) 
{
    int n = X.size();

    std::list<int> ElementsPlusGrand;
    if (n <= 1)
        return X;

    int m = n / 2;
    std::list<std::pair<int, int>> pairs;
    auto it = X.begin();
    for (int i = 0; i < m; i += 2) {
        if (std::next(it, 1) != X.end()) {
            pairs.push_back(std::make_pair(*it, *(std::next(it, 1))));
            // Tri et récupération des éléments plus grands
            if (pairs.back().first > pairs.back().second) {
                ElementsPlusGrand.push_back(pairs.back().first);
                std::swap(pairs.back().first, pairs.back().second);
            } else 
                ElementsPlusGrand.push_back(pairs.back().second);
            }
        std::advance(it, 2);
    }
    ElementsPlusGrand = (TriSpecial(ElementsPlusGrand));
    std::list<int> resultat;
    for (const auto& pair : pairs) {
    auto idx = std::lower_bound(resultat.begin(), resultat.end(), pair.first);
    resultat.insert(idx, pair.first);
    idx = std::lower_bound(resultat.begin(), resultat.end(), pair.second);
    resultat.insert(idx, pair.second);
}
    for (auto it = next(X.begin(), m + 1); it != X.end(); ++it) {
        auto idx = lower_bound(resultat.begin(), resultat.end(), *it);
        resultat.insert(idx, *it);
    }
    return resultat;
}
