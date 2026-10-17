#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"
#include <type_traits>

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
    static_assert(
        std::is_arithmetic<T>::value,
        "T doit etre un type numerique"
    );

public:
    MatrixNumerical();
    MatrixNumerical(std::size_t r, std::size_t c);

    T getDeterminant() const;

    MatrixNumerical<T> operator+(
        const MatrixNumerical<T>& other
    ) const;

    MatrixNumerical<T> operator-(
        const MatrixNumerical<T>& other
    ) const;

    MatrixNumerical<T> operator*(
        const MatrixNumerical<T>& other
    ) const;

    MatrixNumerical<double> getInverse() const;

    MatrixNumerical<double> operator/(
        const MatrixNumerical<T>& other
    ) const;

    static MatrixNumerical<T> getIdentity(int size);
};

#include "MatrixNumerical.cpp"

#endif