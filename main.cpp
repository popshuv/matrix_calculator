#include <iostream>
#include "Matrix.cpp"

int main() {
    // Create two matrices of size 2x2
    Matrix A(2, 2);
    Matrix B(2, 2);

    // Manually set the values for Matrix A
    A.at(0, 0) = 1.0;
    A.at(0, 1) = 2.0;
    A.at(1, 0) = 3.0;
    A.at(1, 1) = 4.0;

    // Manually set the values for Matrix B
    B.at(0, 0) = 5.0;
    B.at(0, 1) = 6.0;
    B.at(1, 0) = 7.0;
    B.at(1, 1) = 8.0;

    // Test Matrix addition
    Matrix C = A + B;
    std::cout << "Matrix A + B:\n";
    std::cout << C.at(0, 0) << " " << C.at(0, 1) << std::endl;
    std::cout << C.at(1, 0) << " " << C.at(1, 1) << std::endl;

    // Test Matrix subtraction
    Matrix D = A - B;
    std::cout << "Matrix A - B:\n";
    std::cout << D.at(0, 0) << " " << D.at(0, 1) << std::endl;
    std::cout << D.at(1, 0) << " " << D.at(1, 1) << std::endl;

    // Test Matrix multiplication
    Matrix E = A * B;
    std::cout << "Matrix A * B:\n";
    std::cout << E.at(0, 0) << " " << E.at(0, 1) << std::endl;
    std::cout << E.at(1, 0) << " " << E.at(1, 1) << std::endl;

    return 0;
}
