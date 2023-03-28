#include "MatrixTools.hpp"
#include <iostream>
#include <random>
#include <cmath>

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

double** create_rand_matrix(size_t n) {
	double** matrix = new double* [n];
	for (size_t i = 0; i < n; i++) {
		matrix[i] = create_rand_vector(n);
	}
	return matrix;
}

double** create_hand_matrix(size_t n) {
	double** matrix = new double* [n];
	for (size_t i = 0; i < n; i++) {
		std::cout << "¬ведите р€д " << i+1 << " матрицы:" << std::endl;
		matrix[i] = create_hand_vector(n);
	}
	return matrix;
}

double* create_rand_vector(size_t n) {
	double* vector = new double[n];
	for (size_t i = 0; i < n; i++) {
		vector[i] = rand() / double(1000);
	}
	return vector;
}

double* create_hand_vector(size_t n) {
	double* vector = new double[n];
	for (size_t i = 0; i < n; i++) {
		std::cin >> vector[i];
	}
	std::cout << std::endl;
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
	std::cout << "+";
	for (size_t j = 0; j < n; j++) {
		std::cout << "-------+";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void print_vector(double* vector, size_t n) {
	std::cout << "+-------+" << std::endl;
	for (size_t i = 0; i < n; i++) {
		std::cout << "|" << vector[i] << "\t|" << std::endl;
		std::cout << "+-------+" << std::endl;
	}
	/*std::cout << std::endl;
	for (size_t i = 0; i < n; i++) {
		std::cout << "|" << vector[i] << "\t";
	}
	std::cout << "|" << std::endl;
	std::cout << "+";
	for (size_t j = 0; j < n; j++) {
		std::cout << "-------+";
	}*/
	std::cout << std::endl;
}

double* mult_matrix_vector(double** matrix, double* vector, size_t n) {
	double* res{ new double[n] {0} };

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			res[i] += matrix[i][j] * vector[j];
		}
	}

	return res;
}

double* vector_copy(double* vector, size_t n) {
	double* copied_vector = new double[n];
	for (size_t i = 0; i < n; i++) {
		copied_vector[i] = vector[i];
	}
	return copied_vector;
}

double** matrix_copy(double** matrix, size_t n) {
	double** copied_matrix = new double* [n];
	for (size_t i = 0; i < n; i++) {
		copied_matrix[i] = vector_copy(matrix[i], n);
	}
	return copied_matrix;
}

void del_vector(double* vector) {
		delete[] vector;
}

void del_matrix(double** matrix, size_t n) {
	for (size_t i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

double error_Gauss(double** A, double* x, double* b, size_t n) {
	double* Ax = mult_matrix_vector(A, x, n);
	double max_err = -1;
	for (size_t i = 0; i < n; i++) {
		double i_err = abs(Ax[i] - b[i]);
		if (i_err > max_err) {
			max_err = i_err;
		}
	}
	return max_err;
}
