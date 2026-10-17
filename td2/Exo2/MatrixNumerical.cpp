
#include <stdexcept>
#include "MatrixNumerical.h"
#include <iostream>
template <typename T>
T MatrixNumerical<T>::getDeterminant() const {
    if (this->rows != this->cols) {
        throw std::invalid_argument(
            "La matrice doit etre carree"
        );
    }

    std::size_t n = this->rows;

    if (n == 0) {
        return T{1};
    }

    if (n == 1) {
        return this->data[0][0];
    }

    if (n == 2) {
        return this->data[0][0] * this->data[1][1]
             - this->data[0][1] * this->data[1][0];
    }

    T determinant{};

    for (std::size_t col = 0; col < n; col++) {
        MatrixNumerical<T> minor;

        minor.rows = n - 1;
        minor.cols = n - 1;
        minor.data.resize(n - 1, std::vector<T>(n - 1));

        for (std::size_t i = 1; i < n; i++) {
            std::size_t minorCol = 0;

            for (std::size_t j = 0; j < n; j++) {
                if (j == col) {
                    continue;
                }

                minor.data[i - 1][minorCol] = this->data[i][j];
                minorCol++;
            }
        }

        T term = this->data[0][col] * minor.getDeterminant();

        if (col % 2 == 0) {
            determinant += term;
        } else {
            determinant -= term;
        }
    }

    return determinant;

}

   template <typename T>
MatrixNumerical<T>::MatrixNumerical()
    : MatrixBase<T>() {}

   template <typename T>
MatrixNumerical<T>::MatrixNumerical(std::size_t r, std::size_t c)
    : MatrixBase<T>(r, c) {}

    template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(
    const MatrixNumerical<T>& other
) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument(
            "Les matrices doivent avoir les memes dimensions"
        );
    }

    MatrixNumerical<T> result(this->rows, this->cols);

    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }

    return result;
}
   

    template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(
    const MatrixNumerical<T>& other
) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument(
            "Les matrices doivent avoir les memes dimensions"
        );
    }

    MatrixNumerical<T> result(this->rows, this->cols);

    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }

    return result;
}


    template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(
    const MatrixNumerical<T>& other
) const {
    if (this->cols != other.rows) {
        throw std::invalid_argument(
            "Dimensions incompatibles pour la multiplication"
        );
    }

    MatrixNumerical<T> result(this->rows, other.cols);

    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < other.cols; j++) {
            for (std::size_t k = 0; k < this->cols; k++) {
                result.data[i][j] +=
                    this->data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}

    template <typename T>
double getCoFactor(
    const MatrixNumerical<T>& matrix,
    std::size_t row,
    std::size_t col
) {
    std::size_t n = matrix.getRows();

    MatrixNumerical<T> minor(n - 1, n - 1);

    std::size_t minorRow = 0;

    for (std::size_t i = 0; i < n; i++) {
        if (i == row) {
            continue;
        }

        std::size_t minorCol = 0;

        for (std::size_t j = 0; j < n; j++) {
            if (j == col) {
                continue;
            }

            minor.addElement(
                minorRow, minorCol, matrix.getElement(i, j)
            );

            minorCol++;
        }

        minorRow++;
    }

    double determinant = static_cast<double>(minor.getDeterminant());

    if ((row + col) % 2 == 0) {
        return determinant;
    }

    return -determinant;
}
    
    template <typename T>
MatrixNumerical<double> MatrixNumerical<T>::getInverse() const {
    if (this->rows != this->cols || this->rows == 0) {
        throw std::invalid_argument(
            "La matrice doit etre carree et non vide"
        );
    }

    double determinant = static_cast<double>(getDeterminant());

    if (determinant == 0.0) {
        throw std::invalid_argument(
            "La matrice n'est pas inversible"
        );
    }

    MatrixNumerical<double> inverse(this->rows, this->cols);

    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            double cofactor = getCoFactor(*this, i, j);

            inverse.addElement(j, i, cofactor / determinant);
        }
    }

    return inverse;
}

    template <typename T>
MatrixNumerical<double> MatrixNumerical<T>::operator/(
    const MatrixNumerical<T>& other
) const {
    if (this->cols != other.getRows()) {
        throw std::invalid_argument(
            "Dimensions incompatibles pour la division"
        );
    }

    MatrixNumerical<double> left(this->rows, this->cols);

    for (std::size_t i = 0; i < this->rows; i++) {
        for (std::size_t j = 0; j < this->cols; j++) {
            left.addElement(
                i, j, static_cast<double>(this->data[i][j])
            );
        }
    }

    return left * other.getInverse();
}
      

    template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int size) {
    if (size <= 0) {
        throw std::invalid_argument(
            "La taille doit etre strictement positive"
        );
    }

    MatrixNumerical<T> identity(size, size);

    for (int i = 0; i < size; i++) {
        identity.addElement(i, i, T{1});
    }

    return identity;
}

    


   