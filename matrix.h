#pragma once

class Matrix {
private:
    int rows, cols;
    double** data;

public:
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);
    ~Matrix();

    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator*(const Matrix& other);

    double& at(int row, int col);
    double at(int row, int col) const;

    int getRows() const;
    int getCols() const;
};

