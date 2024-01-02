/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TriSpecial.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:05:18 by ayael-ou          #+#    #+#             */
/*   Updated: 2024/01/02 16:46:03 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"


std::vector<int> Pmerge::TriSpecial(std::vector<int> &X) {
  int n = X.size();

  std::vector<int> ElementsPlusGrand;
  std::vector<std::pair<int, int>> pairs;
  if (n == 1)
    return X;

  int m = n / 2;
  for (int i = 0; i < m; i += 2) {
    pairs.push_back(std::make_pair(X[i], X[i + 1]));
    if ( pairs[i].first > pairs[i].second)
      ElementsPlusGrand.push_back(pairs[i].first);
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

  for (int i = m + 1; i < n; ++i) {
    std::vector<int>::iterator idx = std::lower_bound(resultat.begin(), resultat.end(), X[i]);
    resultat.insert(idx, X[i]);
  }
  return resultat;
}



