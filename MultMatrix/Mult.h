#pragma once
#include "Matrix.h"

// Функция для умножения двух матриц MatrixManager2dStorage
MatrixManager2dStorage multiply_matrices_to_2dstorage(const Matrix& mat1, const Matrix& mat2);

MatrixManager1dStorage multiply_matrices_to_1dstorage_ijk(const Matrix& mat1, const Matrix& mat2);

MatrixManager1dStorage multiply_matrices_to_1dstorage_ikj(const Matrix& mat1, const Matrix& mat2);

MatrixManager1dStorage multiply_matrices_to_1dstorage_jik(const Matrix& mat1, const Matrix& mat2);

MatrixManager1dStorage multiply_matrices_to_1dstorage_jki(const Matrix& mat1, const Matrix& mat2);

MatrixManager1dStorage multiply_matrices_to_1dstorage_kij(const Matrix& mat1, const Matrix& mat2);

MatrixManager1dStorage multiply_matrices_to_1dstorage_kji(const Matrix& mat1, const Matrix& mat2);
