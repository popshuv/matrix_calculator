class Matrix {

private:
    int rows, cols;
    double** data;

public:
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        data = new double* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
        }
    }

    Matrix(const Matrix& other) {
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

    ~Matrix() {
		for (int i = 0; i < rows; ++i) {
			delete[] data[i];
		}
		delete[] data;
	}

    Matrix operator+(const Matrix& other) {
		Matrix result(rows, cols);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				result.data[i][j] = data[i][j] + other.data[i][j];
			}
		}
		return result;
	}

    Matrix operator-(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) {
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

    double& at(int row, int col) {
        return data[row][col];
    }

    double at(int row, int col) const {
        return data[row][col];
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }
};
