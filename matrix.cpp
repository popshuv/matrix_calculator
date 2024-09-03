#include "matrix.h"
#include <iostream>

// Constructor
Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    data = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
    }
}

// Copy constructor
Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;
    data = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Destructor
Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

// Addition operator
Matrix Matrix::operator+(const Matrix& other) {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Subtraction operator
Matrix Matrix::operator-(const Matrix& other) {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// Multiplication operator
Matrix Matrix::operator*(const Matrix& other) {
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

// Transpose the matrix
Matrix Matrix::transpose() {
    Matrix result(cols, rows);  
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[j][i] = data[i][j];  
        }
    }
    return result;
}


// Element access (non-const)
double& Matrix::at(int row, int col) {
    return data[row][col];
}

// Element access (const)
double Matrix::at(int row, int col) const {
    return data[row][col];
}

// Get number of rows
int Matrix::getRows() const {
    return rows;
}

// Get number of columns
int Matrix::getCols() const {
    return cols;
}

