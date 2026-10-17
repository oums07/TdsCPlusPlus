#include <iostream>
#include <vector>
#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"

int main() {
    std::vector<int> elements = {2, 6, 1, 8, 11, 12};
    int target = 11;

    LinearSearch linear;
    JumpSearch jump;
    BinarySearch binary;

    std::vector<int> linearElements = elements;
    std::vector<int> jumpElements = elements;
    std::vector<int> binaryElements = elements;

    std::cout << "Linear Search :\n";

    int result = linear.search(linearElements, target);
    linear.displaySearchResults(std::cout, result, target);

    std::cout << "\nJump Search :\n";

    result = jump.search(jumpElements, target);
    jump.displaySearchResults(std::cout, result, target);

    std::cout << "\nBinary Search :\n";

    result = binary.search(binaryElements, target);
    binary.displaySearchResults(std::cout, result, target);

    return 0;
}