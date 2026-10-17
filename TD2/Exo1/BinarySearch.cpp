#include "BinarySearch.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std ;


int BinarySearch::search(std::vector<int>& elements, int target) {
    numberComparisons = 0;

    std::sort(elements.begin(), elements.end());

    int left = 0;
    int right = static_cast<int>(elements.size()) - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        numberComparisons++;

        if (elements[middle] == target) {
            return middle;
        }

        numberComparisons++;

        if (elements[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}