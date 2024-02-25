#include "Mult.h"
#include <iostream>

using namespace std;

// ������� ��� ��������� ���� ������ MatrixManager2dStorage
MatrixManager2dStorage multiply_matrices_to_2dstorage(const Matrix& mat1, const Matrix& mat2) {
    // ���������, ��� ���������� �������� ������ ������� ����� ���������� ����� ������ �������
    if (mat1.get_cols() != mat2.get_rows()) {
        cerr << "���������� �������� �������: ������������ �������" << endl;
        return MatrixManager2dStorage();
    }

    int rows = mat1.get_rows();
    int cols = mat2.get_cols();
    int common_dim = mat1.get_cols(); // ��� mat2.get_rows()

    // ������� ����� ������� ��� �������� ���������� ���������
    MatrixManager2dStorage result(rows, cols);

    // ��������� ������
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < common_dim; ++k) {
                result[i][j] += mat1.at(i, k) * mat2.at(k, i);
            }
        }
    }

    return result;
}

// ������� ��� ��������� ���� ������ MatrixManager2dStorage
MatrixManager1dStorage multiply_matrices_to_1dstorage_ijk(const Matrix& mat1, const Matrix& mat2) {
    // ���������, ��� ���������� �������� ������ ������� ����� ���������� ����� ������ �������
    if (mat1.get_cols() != mat2.get_rows()) {
        cerr << "���������� �������� �������: ������������ �������" << endl;
        return MatrixManager1dStorage();
    }

    int rows = mat1.get_rows();
    int cols = mat2.get_cols();
    int common_dim = mat1.get_cols(); // ��� mat2.get_rows()

    // ������� ����� ������� ��� �������� ���������� ���������
    MatrixManager1dStorage result(rows, cols);

    // ��������� ������
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < common_dim; ++k) {
                result.at(i, j)+= mat1.at(i, k) * mat2.at(k, j);
            }
        }
    }

    return result;
}

MatrixManager1dStorage multiply_matrices_to_1dstorage_ikj(const Matrix& mat1, const Matrix& mat2) {
    // ���������, ��� ���������� �������� ������ ������� ����� ���������� ����� ������ �������
    if (mat1.get_cols() != mat2.get_rows()) {
        cerr << "���������� �������� �������: ������������ �������" << endl;
        return MatrixManager1dStorage();
    }

    int rows = mat1.get_rows();
    int cols = mat2.get_cols();
    int common_dim = mat1.get_cols(); // ��� mat2.get_rows()

    // ������� ����� ������� ��� �������� ���������� ���������
    MatrixManager1dStorage result(rows, cols);

    // ��������� ������
    for (int i = 0; i < rows; ++i) {
        for (int k = 0; k < common_dim; ++k) {
            for (int j = 0; j < cols; ++j) {
                result.at(i, j)+= mat1.at(i, k) * mat2.at(k, j);
            }
        }
    }

    return result;
}

MatrixManager1dStorage multiply_matrices_to_1dstorage_jik(const Matrix& mat1, const Matrix& mat2) {
    // ���������, ��� ���������� �������� ������ ������� ����� ���������� ����� ������ �������
    if (mat1.get_cols() != mat2.get_rows()) {
        cerr << "���������� �������� �������: ������������ �������" << endl;
        return MatrixManager1dStorage();
    }

    int rows = mat1.get_rows();
    int cols = mat2.get_cols();
    int common_dim = mat1.get_cols(); // ��� mat2.get_rows()

    // ������� ����� ������� ��� �������� ���������� ���������
    MatrixManager1dStorage result(rows, cols);

    // ��������� ������
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            for (int k = 0; k < common_dim; ++k) {
                result.at(i, j)+= mat1.at(i, k) * mat2.at(k, j);
            }
        }
    }

    return result;
}

MatrixManager1dStorage multiply_matrices_to_1dstorage_jki(const Matrix& mat1, const Matrix& mat2) {
    // ���������, ��� ���������� �������� ������ ������� ����� ���������� ����� ������ �������
    if (mat1.get_cols() != mat2.get_rows()) {
        cerr << "���������� �������� �������: ������������ �������" << endl;
        return MatrixManager1dStorage();
    }

    int rows = mat1.get_rows();
    int cols = mat2.get_cols();
    int common_dim = mat1.get_cols(); // ��� mat2.get_rows()

    // ������� ����� ������� ��� �������� ���������� ���������
    MatrixManager1dStorage result(rows, cols);

    // ��������� ������
    for (int j = 0; j < cols; ++j) {
        for (int k = 0; k < common_dim; ++k) {
            for (int i = 0; i < rows; ++i) {
                result.at(i, j)+= mat1.at(i, k) * mat2.at(k, j);
            }
        }
    }

    return result;
}

MatrixManager1dStorage multiply_matrices_to_1dstorage_kij(const Matrix& mat1, const Matrix& mat2) {
    // ���������, ��� ���������� �������� ������ ������� ����� ���������� ����� ������ �������
    if (mat1.get_cols() != mat2.get_rows()) {
        cerr << "���������� �������� �������: ������������ �������" << endl;
        return MatrixManager1dStorage();
    }

    int rows = mat1.get_rows();
    int cols = mat2.get_cols();
    int common_dim = mat1.get_cols(); // ��� mat2.get_rows()

    // ������� ����� ������� ��� �������� ���������� ���������
    MatrixManager1dStorage result(rows, cols);

    // ��������� ������
    for (int k = 0; k < common_dim; ++k) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.at(i, j)+= mat1.at(i, k) * mat2.at(k, j);
            }
        }
    }

    return result;
}

MatrixManager1dStorage multiply_matrices_to_1dstorage_kji(const Matrix& mat1, const Matrix& mat2) {
    // ���������, ��� ���������� �������� ������ ������� ����� ���������� ����� ������ �������
    if (mat1.get_cols() != mat2.get_rows()) {
        cerr << "���������� �������� �������: ������������ �������" << endl;
        return MatrixManager1dStorage();
    }

    int rows = mat1.get_rows();
    int cols = mat2.get_cols();
    int common_dim = mat1.get_cols(); // ��� mat2.get_rows()

    // ������� ����� ������� ��� �������� ���������� ���������
    MatrixManager1dStorage result(rows, cols);

    // ��������� ������
    for (int k = 0; k < common_dim; ++k) {
        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                result.at(i, j)+= mat1.at(i, k) * mat2.at(k, j);
            }
        }
    }

    return result;
}