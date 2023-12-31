/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jonshon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:13:24 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/12/31 16:13:55 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <cmath>

// Merge-insert sort function
template <typename Container>
void mergeInsertSort(Container& data) {
    for (int i = 0; i < data.size(); i++) {
        int j = 0;
        while (j < i && data[j] < data[i]) {
            j++;
        }
        if (i > 0) {
            data.push_back(data[i]);
            data.erase(data.begin() + i);
        }
        for (int k = i - 1; k >= j; k--) {
            data[k + 1] = data[k];
        }
        data[j] = data[i];
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: PmergeMe <positive_integer_sequence>" << std::endl;
        return 1;
    }

    std::vector<int> dataVec;
    std::list<int> dataList;

    // Parse the input string into integer sequence
    std::string inputString(argv[1]);
    for (char c : inputString) {
        if (isdigit(c)) {
            int value = c - '0';
            dataVec.push_back(value);
            dataList.push_back(value);
        }
    }

    // Sort using std::vector
    auto startTimeVec = std::chrono::high_resolution_clock::now();
    mergeInsertSort(dataVec);
    auto endTimeVec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> durationVec = endTimeVec - startTimeVec;

    // Sort using std::list
    auto startTimeList = std::chrono::high_resolution_clock::now();
    mergeInsertSort(dataList);
    auto endTimeList = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> durationList = endTimeList - startTimeList;

    // Display unsorted and sorted sequences
    std::cout << "Before: ";
    for (int value : dataVec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (int value : dataVec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Display sorting time for each container
    std::cout << "Time to process a range of " << dataVec.size() << " elements with std::[..] : " << durationVec.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << dataVec.size() << " elements with std::list : " << durationList.count() << " us" << std::endl;

    return 0;
}
