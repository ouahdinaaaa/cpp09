/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TriSpecial.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:05:18 by ayael-ou          #+#    #+#             */
/*   Updated: 2024/01/01 21:39:49 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>


std::vector<int> TriSpecial(std::vector<int> &X) {
  int n = X.size();

  std::vector<int> ElementsPlusGrand;
  std::vector<std::pair<int, int>> pairs;
  if (n == 1) {
    return X;
  }

  int m = n / 2;

  for (int i = 0; i < m; i += 2) {
    pairs.push_back(std::make_pair(X[i], X[i + 1]));
    if (pairs[i].second < pairs[i].first) {
      ElementsPlusGrand.push_back(pairs[i].first);
      std::swap(pairs[i].first, pairs[i].second);
    }
    else
        ElementsPlusGrand.push_back(pairs[i].second);
  }

  ElementsPlusGrand = (TriSpecial(ElementsPlusGrand));

  std::vector<int> resultat;

for (const auto& pair : pairs) {
    auto idx = std::lower_bound(resultat.begin(), resultat.end(), pair.first);
    resultat.insert(idx, pair.first);
    idx = std::lower_bound(resultat.begin(), resultat.end(), pair.second);
    resultat.insert(idx, pair.second);
}

  for (int i = m; i < n; i++) {
    std::vector<int>::iterator idx = std::lower_bound(resultat.begin(), resultat.end(), X[i]);
    resultat.insert(idx, X[i]);
  }
  return resultat;
}



int main() 
{
    std::vector<int> Desorder = {1203, 1345, 1732, 2785, 2900, 2822, 2745, 2668, 2591, 2514, 2437, 2360, 2283, 2206, 2129, 2052, 1975, 1898, 1821, 1744, 1667, 1590, 1513, 1436, 1359, 1282, 1205, 1128, 1051, 974, 897, 820, 743, 666, 589, 512, 435, 358, 281, 204, 127, 50, -27, -104, -181, -258, -335, -412, -489, -566, -643, -720, -797, -874, -951, -1028, -1105, -1182, -1259, -1336, -1413, -1490, -1567, -1644, -1721, -1798, -1875, -1952, -2029, -2106, -2183, -2260, -2337, -2414, -2491, -2568, -2645, -2722, -2799};
    std::vector<int> Tried = TriSpecial(Desorder);
    // Affichage des éléments triés
    std::cout << "\nListe triée : ";
    for (std::vector<int>::iterator it = Tried.begin(); it != Tried.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}

