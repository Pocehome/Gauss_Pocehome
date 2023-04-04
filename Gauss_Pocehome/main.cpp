#include <iostream>
#include <locale>
#include "MatrixTools.hpp"

int main() {
	setlocale(LC_CTYPE, "Russian");
	int n;

	while (true) {
		std::cout << "Choose how to create matrix A and vector b:" << std::endl;
		std::cout << "1) Automatic" << std::endl;
		std::cout << "2) Manual" << std::endl;

		int input_method;
		std::cin >> input_method;

		if ((input_method != 1) & (input_method != 2)) {
			std::cout << "Creation method specified incorrectly!!!" << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;
			std::cout << std::endl;
			continue;
		}

		std::cout << std::endl;
		std::cout << "Enter the size of matrix A: ";
		std::cin >> n; 
		
		if (n < 1) {
			std::cout << "Incorrect matrix size!!!" << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;
			std::cout << std::endl;
			continue;
		}
		std::cout << std::endl;

		double** A = nullptr;
		double* b = nullptr;
		double* x = nullptr;

		switch (input_method) {
		case 1:
			A = create_rand_matrix(n);
			b = create_rand_vector(n);
			x = create_rand_vector(n);
			break;
		case 2:
			std::cout << "Input matrix A:" << std::endl;
			A = create_hand_matrix(n);
			std::cout << "Input vector b:" << std::endl;
			b = create_hand_vector(n);
			x = create_rand_vector(n);
			break;
		default:
			std::cout << "Creation method specified incorrectly!!!" << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;
			std::cout << std::endl;
			break;
		}

		double** A_copy = matrix_copy(A, n);
		double* b_copy = vector_copy(b, n);

		//std::cout << "Matrix A:" << std::endl;
		//print_matrix(A, n);
		//std::cout << "Vector b:" << std::endl;
		//print_vector(b, n);

		Gauss(A, b, x, n);

		//std::cout << "Vector x:" << std::endl;
		//print_vector(x, n);

		double err = error_Gauss(A_copy, x, b_copy, n);
		std::cout << "The max error is " << err << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << std::endl;

		del_matrix(A, n);
		del_vector(b);
		del_vector(x);
		del_matrix(A_copy, n);
		del_vector(b_copy);
	}
}