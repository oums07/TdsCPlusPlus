#include "MatrixBase.h"
#include <vector>
#include <cstddef>
#include <iostream>

template <typename T>
MatrixBase<T>::MatrixBase() : rows(0), cols(0) {}

template <typename T>
MatrixBase<T>::MatrixBase(std::size_t r, std::size_t c)
    : data(r, std::vector<T>(c)), rows(r), cols(c) {}

template <typename T>
void MatrixBase<T>::addElement(
    std::size_t row, std::size_t col, const T& value
) {
    data.at(row).at(col) = value;
}

template <typename T>
T MatrixBase<T>::getElement(
    std::size_t row, std::size_t col
) const {
    return data.at(row).at(col);
}
template <typename T>
std::size_t MatrixBase<T>::getRows() const {
    return rows;
}

template <typename T>
std::size_t MatrixBase<T>::getCols() const {
    return cols;
}
template <typename T>
void MatrixBase<T>::Display() const {
    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < cols; j++) {
            std::cout << data.at(i).at(j) << ' ';
        }

        std::cout << '\n';
    }
}