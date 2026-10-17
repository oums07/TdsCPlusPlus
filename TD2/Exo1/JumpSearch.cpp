#include "JumpSearch.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std ;


int JumpSearch::search(std::vector<int>& elements, int target) {
    numberComparisons = 0;

    std::sort(elements.begin(), elements.end());

    int n = static_cast<int>(elements.size());

    if (n == 0) {
        return -1;
    }

    int jump = static_cast<int>(std::sqrt(n));
    int start = 0;
    int end = jump;

    while (true) {
        numberComparisons++;

        if (elements[std::min(end, n) - 1] >= target) {
            break;
        }

        start = end;

        if (start >= n) {
            return -1;
        }

        end += jump;
    }

    for (int i = start; i < std::min(end, n); i++) {
        numberComparisons++;

        if (elements[i] == target) {
            return i;
        }
    }

    return -1;
}