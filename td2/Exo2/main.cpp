#include <iostream>
#include <exception>
#include "MatrixNumerical.h"
#include "MatrixBase.h"


int main() {
    try {
        MatrixNumerical<double> a(2, 2);
        MatrixNumerical<double> b(2, 2);

        a.addElement(0, 0, 1);
        a.addElement(0, 1, 2);
        a.addElement(1, 0, 3);
        a.addElement(1, 1, 4);

        b.addElement(0, 0, 2);
        b.addElement(0, 1, 0);
        b.addElement(1, 0, 0);
        b.addElement(1, 1, 2);

        std::cout << "Matrice A :\n";
        a.Display();

        std::cout << "\nMatrice B :\n";
        b.Display();

        std::cout << "\nLignes de A : " << a.getRows() << '\n';
        std::cout << "Colonnes de A : " << a.getCols() << '\n';
        std::cout << "Element A(0, 1) : "
                  << a.getElement(0, 1) << '\n';

        std::cout << "\nA + B :\n";
        (a + b).Display();

        std::cout << "\nA - B :\n";
        (a - b).Display();

        std::cout << "\nA * B :\n";
        (a * b).Display();

        std::cout << "\nDeterminant de A : "
                  << a.getDeterminant() << '\n';

        std::cout << "\nInverse de A :\n";
        a.getInverse().Display();

        std::cout << "\nA / B :\n";
        (a / b).Display();

        std::cout << "\nMatrice identite 3 x 3 :\n";
        MatrixNumerical<double>::getIdentity(3).Display();
    }
    catch (const std::exception& error) {
        std::cerr << "Erreur : " << error.what() << '\n';
        return 1;
    }

    return 0;
}