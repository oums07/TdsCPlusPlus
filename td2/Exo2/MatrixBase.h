#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <vector>
#include <cstddef>

template <typename T>
class MatrixBase {
protected:
    std::vector<std::vector<T>> data;
    std::size_t rows;
    std::size_t cols;

public:
    MatrixBase();
    MatrixBase(std::size_t r, std::size_t c);

    void addElement(std::size_t row, std::size_t col, const T& value);
    T getElement(std::size_t row, std::size_t col) const;

    std::size_t getRows() const;
    std::size_t getCols() const;

    void Display() const;
};

#include "MatrixBase.cpp"

#endif