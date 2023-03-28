#include "MatrixTools.hpp"
#include <iostream>
#include <random>

void Gauss(double** A, double* b, double* x, size_t n) {
	// пр€мой ход
	for (size_t i = 0; i < n; i++) {
		for (size_t j = i + 1; j < n; j++) {
			double coef = A[j][i] / A[i][i];
			for (size_t k = i; k < n; k++) {
				A[j][k] = A[j][k] - A[i][k] * coef;
			}
			b[j] -= b[i] * coef;
		}
	}

	// обратный ход
	for (int i = n - 1; i >= 0; i--) {
		x[i] = 0;
		for (int j = i + 1; j < n; j++) {
			x[i] += x[j] * A[i][j];
		}
		x[i] = (b[i] - x[i]) / A[i][i];
	}
}

void matrix_rand_fill(double** matrix, size_t n) {
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			matrix[i][j] = rand() / double(1000);
		}
	}
}

void matrix_hand_fill(double** matrix, size_t n) {
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

void vector_rand_fill(double* vector, size_t n) {
	for (size_t i = 0; i < n; i++) {
		vector[i] = rand() / double(1000);
	}
}

void vector_hand_fill(double* vector, size_t n) {
	for (size_t i = 0; i < n; i++) {
		std::cin >> vector[i];
	}
}

double** create_rand_matrix(size_t n) {
	double** matrix = new double* [n];
	for (size_t i = 0; i < n; i++) {
		matrix[i] = new double[n];
	}
	matrix_rand_fill(matrix, n);
	return matrix;
}

double** create_hand_matrix(size_t n) {
	std::cout << "¬ведите матрицу A: ";
	double** matrix = new double* [n];
	for (size_t i = 0; i < n; i++) {
		matrix[i] = new double[n];
	}
	matrix_hand_fill(matrix, n);
	return matrix;
}

double* create_rand_vector(size_t n) {
	double* vector = new double[n];
	vector_rand_fill(vector, n);
	return vector;
}

double* create_hand_vector(size_t n) {
	std::cout << "¬ведите вектор b: ";
	double* vector = new double[n];
	vector_hand_fill(vector, n);
	return vector;
}

void print_matrix(double** matrix, size_t n) {
	for (size_t i = 0; i < n; i++) {
		std::cout << "+";
		for (size_t j = 0; j < n; j++) {
			std::cout << "-------+";
		}
		std::cout << std::endl;
		for (size_t j = 0; j < n; j++) {
			std::cout << "|" << matrix[i][j] << "\t";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "|";
	for (size_t j = 0; j < n; j++) {
		std::cout << "-------+";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void print_vector(double* vector, size_t n) {
	std::cout << "+";
	for (size_t j = 0; j < n; j++) {
		std::cout << "-------+";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < n; i++) {
		std::cout << "|" << vector[i] << "\t";
	}
	std::cout << "|" << std::endl;
	std::cout << "+";
	for (size_t j = 0; j < n; j++) {
		std::cout << "-------+";
	}
	std::cout << std::endl;
}
