/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TriSpecial.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:05:18 by ayael-ou          #+#    #+#             */
/*   Updated: 2024/01/04 20:37:42 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"


std::vector<int> Pmerge::TriSpecial(std::vector<int> &X) {
  int n = X.size();

  std::vector<std::pair<int, int>> pairs;
  std::vector<int> ElementsPlusGrand;
  if (n == 1)
    return X;

  int m = n / 2;
  auto it = X.begin();
  for (int i = 0; i < m; i += 2) {
    if (std::next(it, 1) != X.end()){
      pairs.push_back(std::make_pair(*it, *(std::next(it, 1))));
      if (pairs.back().first > pairs.back().second){
        ElementsPlusGrand.push_back(pairs.back().first);
        std::swap(pairs.back().first, pairs.back().second);
      } else
        ElementsPlusGrand.push_back(pairs.back().second);
    } std::advance(it, 2);
  } ElementsPlusGrand = (TriSpecial(ElementsPlusGrand));
  std::vector<int> resultat;

for (const auto& pair : pairs) {
    auto idx = std::lower_bound(resultat.begin(), resultat.end(), pair.first);
    resultat.insert(idx, pair.first);
    idx = std::lower_bound(resultat.begin(), resultat.end(), pair.second);
    resultat.insert(idx, pair.second);
} for (int i = m + 1; i < n; ++i) {
    std::vector<int>::iterator idx = std::lower_bound(resultat.begin(), resultat.end(), X[i]);
    resultat.insert(idx, X[i]);
  } if (resultat.size() != X.size()){
    auto it = next(X.begin(), m);
    auto idx = std::lower_bound(resultat.begin(), resultat.end(), *it);
    resultat.insert(idx, *it);
  } return resultat;
}



