// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <random>
#include <chrono> 
#include <functional> 

using namespace std;

#include "Matrix.h"
#include "Mult.h"

ostream& operator<<(ostream& os, const Matrix& matrix) {
    int rows = matrix.get_rows();
    int cols = matrix.get_cols();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            os << matrix[i][j] << " ";
        }
        os << endl;
    }

    return os;
}


void generate_matrix_to_file(int n, int m, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
        return;
    }

    file << n << " " << m << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); // Распределение значений от 1 до 100 (можно изменить по вашему усмотрению)

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            file << dis(gen) << " ";
        }
        file << std::endl;
    }

    file.close();
}

// Функция для измерения времени выполнения другой функции
template<typename F, typename... Args>
double measureTime(const F& func, Args&&... args) {
    auto start = chrono::steady_clock::now(); // Записываем текущее время до выполнения функции
    func(forward<Args>(args)...); // Выполняем переданную функцию
    auto end = chrono::steady_clock::now(); // Записываем текущее время после выполнения функции

    // Вычисляем разницу во времени и преобразуем её в миллисекунды
    return chrono::duration<double, milli>(end - start).count();
};


void storage2d_test() {

    cout << "2d storage test is runnig..." << endl;

    MatrixManager2dStorage m512, m1024, m2048;
    m512.read_matrix_from_file("m512.txt");
    m1024.read_matrix_from_file("m1024.txt");
    m2048.read_matrix_from_file("m2048.txt");

    double sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += measureTime(multiply_matrices_to_2dstorage, m512, m512) / 1000;
    }
    cout << "Average time of 512x512 is " << sum / 10 << endl;

    sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += measureTime(multiply_matrices_to_2dstorage, m1024, m1024) / 1000;
    }
    cout << "Average time of 1024x1024 is " << sum / 3 << endl;

    sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += measureTime(multiply_matrices_to_2dstorage, m2048, m2048) / 1000;
    }
    cout << "Average time of 2048x2048 is " << sum / 3 << endl;
    cout << "2d storage test end" << endl;
}

using MultiplyFunction = std::function<MatrixManager1dStorage(const Matrix&, const Matrix&)>;

void storage1d_test(const MultiplyFunction& mult, string message) {
    cout << "1d storage test is runnig..." << endl;
    cout << message << endl;

    MatrixManager1dStorage m512, m1024, m2048;
    m512.read_matrix_from_file("m512.txt");
    m1024.read_matrix_from_file("m1024.txt");
    m2048.read_matrix_from_file("m2048.txt");

    double sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += measureTime(mult, m512, m512) / 1000;
    }
    cout << "Average time of 512x512 is " << sum / 10 << endl;

    sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += measureTime(mult, m1024, m1024) / 1000;
    }
    cout << "Average time of 1024x1024 is " << sum / 3 << endl;

    sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += measureTime(mult, m2048, m2048) / 1000;
    }
    cout << "Average time of 2048x2048 is " << sum / 3 << endl;
    cout << "1d storage test end" << endl;
}
/*
int main() {

    storage2d_test();

    storage1d_test(multiply_matrices_to_1dstorage_ijk, "ijk");
    storage1d_test(multiply_matrices_to_1dstorage_ikj, "ikj");
    storage1d_test(multiply_matrices_to_1dstorage_kij, "kij");
    storage1d_test(multiply_matrices_to_1dstorage_kji, "kji");
    storage1d_test(multiply_matrices_to_1dstorage_jik, "jik");
    storage1d_test(multiply_matrices_to_1dstorage_jki, "jki");

    generate_matrix_to_file(512, 512, "m512.txt");
    generate_matrix_to_file(1024, 1024, "m1024.txt");
    generate_matrix_to_file(2048, 2048, "m2048.txt");
}*/




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
