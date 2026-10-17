#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <vector>
#include <ostream>

class SearchingAlgorithm {
protected:
    long int numberComparisons;

    static long int totalComparisons;
    static long int totalSearch;
    static double averageComparisons;

public:
    SearchingAlgorithm();

    virtual ~SearchingAlgorithm() = default;

    virtual int search(std::vector<int>& elements, int target) = 0;

    void displaySearchResults(std::ostream& os, int result, int target);
};

#endif