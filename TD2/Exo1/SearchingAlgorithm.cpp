#include "SearchingAlgorithm.h"
#include <iostream>
#include <vector>
using namespace std ;
#include "SearchingAlgorithm.h"

long int SearchingAlgorithm::totalComparisons = 0;
long int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

void SearchingAlgorithm::displaySearchResults(
    std::ostream& os, int result, int target
) {
    totalComparisons += numberComparisons;
    totalSearch++;

    averageComparisons =
        static_cast<double>(totalComparisons) / totalSearch;

    os << "Target : " << target << '\n';
    os << "Result : " << result << '\n';
    os << "Nombre de comparaisons : " << numberComparisons << '\n';
    os << "Total de comparaisons : " << totalComparisons << '\n';
    os << "Moyenne des comparaisons : " << averageComparisons << '\n';


 }
