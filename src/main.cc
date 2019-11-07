#include <iostream>

#include "TMatrix.hpp"

int main() {
    TMatrix<int> matrix(10, 10);
    matrix.setValue(0, 0, 14);
    std::cout << "siema\n" << matrix.printMatrix();
}