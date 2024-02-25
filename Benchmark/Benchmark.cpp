#include <benchmark/benchmark.h>
#include <iostream>
#include "Matrix.h"
#include "Mult.h"

class MatrixFixture : public benchmark::Fixture {
public:
    static void SetUpTestCase() {
        if (!is_already_process) {
            mat2d512.read_matrix_from_file("m512.txt");
            mat2d1024.read_matrix_from_file("m1024.txt");
            mat2d2048.read_matrix_from_file("m2048.txt");

            mat1d512.read_matrix_from_file("m512.txt");
            mat1d1024.read_matrix_from_file("m1024.txt");
            mat1d2048.read_matrix_from_file("m2048.txt");
            is_already_process = true;
        }
    }

    void SetUp(const ::benchmark::State& state) override {
        // Вы можете выполнить другие действия, если необходимо
    }

    void TearDown(const ::benchmark::State& state) override {
        // Optionally clean up resources if needed
    }

    static MatrixManager2dStorage mat2d512;
    static MatrixManager2dStorage mat2d1024;
    static MatrixManager2dStorage mat2d2048;

    static MatrixManager2dStorage mat1d512;
    static MatrixManager2dStorage mat1d1024;
    static MatrixManager2dStorage mat1d2048;

    static bool is_already_process;
};

MatrixManager2dStorage MatrixFixture::mat2d512;
MatrixManager2dStorage MatrixFixture::mat2d1024;
MatrixManager2dStorage MatrixFixture::mat2d2048;

MatrixManager2dStorage MatrixFixture::mat1d512;
MatrixManager2dStorage MatrixFixture::mat1d1024;
MatrixManager2dStorage MatrixFixture::mat1d2048;

bool MatrixFixture::is_already_process = false;


BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_2d_512x512)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_2dstorage(mat2d512, mat2d512);
        benchmark::DoNotOptimize(result);
    }
}

// Register the benchmark
BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_2d_512x512)
->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_2d_1024x1024)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_2dstorage(mat2d1024, mat2d1024);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_2d_1024x1024)
->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_2d_2048x2048)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_2dstorage(mat2d2048, mat2d2048);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_2d_2048x2048)
->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_512x512_ijk)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_ijk(mat1d512, mat1d512);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_1024x1024_ijk)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_ijk(mat1d1024, mat1d1024);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_2048x2048_ijk)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_ijk(mat1d2048, mat1d2048);
        benchmark::DoNotOptimize(result);
    }
}


BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_512x512_ijk)
->Unit(benchmark::kSecond);

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_1024x1024_ijk)
->Unit(benchmark::kSecond);

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_2048x2048_ijk)
->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_512x512_ikj)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_ikj(mat1d512, mat1d512);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_1024x1024_ikj)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_ikj(mat1d1024, mat1d1024);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_2048x2048_ikj)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_ikj(mat1d2048, mat1d2048);
        benchmark::DoNotOptimize(result);
    }
}


BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_512x512_ikj)
->Unit(benchmark::kSecond);

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_1024x1024_ikj)
->Unit(benchmark::kSecond);

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_2048x2048_ikj)
->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_512x512_jik)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_jik(mat1d512, mat1d512);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_1024x1024_jik)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_jik(mat1d1024, mat1d1024);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_2048x2048_jik)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_jik(mat1d2048, mat1d2048);
        benchmark::DoNotOptimize(result);
    }
}


BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_512x512_jik)
->Unit(benchmark::kSecond);

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_1024x1024_jik)
->Unit(benchmark::kSecond);

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_2048x2048_jik)
->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_512x512_jki)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_jki(mat1d512, mat1d512);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_1024x1024_jki)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_jki(mat1d1024, mat1d1024);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_2048x2048_jki)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_jki(mat1d2048, mat1d2048);
        benchmark::DoNotOptimize(result);
    }
}


BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_512x512_jki)
->Unit(benchmark::kSecond);

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_1024x1024_jki)
->Unit(benchmark::kSecond);

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_2048x2048_jki)
->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_512x512_kij)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_kij(mat1d512, mat1d512);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_1024x1024_kij)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_kij(mat1d1024, mat1d1024);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_2048x2048_kij)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_kij(mat1d2048, mat1d2048);
        benchmark::DoNotOptimize(result);
    }
}


BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_512x512_kij)
->Unit(benchmark::kSecond);

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_1024x1024_kij)
->Unit(benchmark::kSecond);

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_2048x2048_kij)
->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_512x512_kji)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_kji(mat1d512, mat1d512);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_1024x1024_kji)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_kji(mat1d1024, mat1d1024);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_1d_2048x2048_kji)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_1dstorage_kji(mat1d2048, mat1d2048);
        benchmark::DoNotOptimize(result);
    }
}


BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_512x512_kji)
->Unit(benchmark::kSecond);

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_1024x1024_kji)
->Unit(benchmark::kSecond);

BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_1d_2048x2048_kji)
->Unit(benchmark::kSecond);

BENCHMARK_MAIN();
