#include <iostream>
using namespace std;

struct Matrix {
    int rows;
    int cols;
    int elements[3][3]; 
};

Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    Matrix result;
    result.rows = A.rows;
    result.cols = B.cols;

    for (int i = 0; i < result.rows; ++i) {
        for (int j = 0; j < result.cols; ++j) {
            result.elements[i][j] = 0;
        }
    }

    for (int i = 0; i < A.rows; ++i) {
        for (int j = 0; j < B.cols; ++j) {
            for (int k = 0; k < A.cols; ++k) {
                result.elements[i][j] += A.elements[i][k] * B.elements[k][j];
            }
        }
    }

    return result;
}

void displayMatrix(const Matrix& M) {
    for (int i = 0; i < M.rows; ++i) {
        for (int j = 0; j < M.cols; ++j) {
            cout << M.elements[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Matrix A = {3, 3, {
        {2, 3, -1},
        {-2, 4, 1},
        {17, 0, 0}
    }};

    Matrix B = {3, 3, {
        {4, 6, -2},
        {5, 8, 9},
        {1, 3, 7}
    }};

    Matrix result = multiplyMatrices(A, B);

    cout << "Product of Matrix A and Matrix B:" << endl;
    displayMatrix(result);

}