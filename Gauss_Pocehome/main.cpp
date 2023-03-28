#include <iostream>
#include <locale>
#include "MatrixTools.hpp"

int main() {
	setlocale(LC_CTYPE, "Russian");
	size_t n;
	std::cout << "¬ведите размер матрицы: ";
	std::cin >> n;

	//double** matrix = create_rand_matrix(n);
	double** matrix = create_hand_matrix(n);
	print_matrix(matrix, n);

	double* x = create_rand_vector(n);
	//double* b = create_rand_vector(n);
	double* b = create_hand_vector(n);

	print_vector(b, n);
	Gauss(matrix, b, x, n);
	print_vector(b, n);
	print_vector(x, n);
}
