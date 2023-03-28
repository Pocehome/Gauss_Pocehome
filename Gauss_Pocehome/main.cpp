#include <iostream>
#include <locale>
#include "MatrixTools.hpp"

int main() {
	setlocale(LC_CTYPE, "Russian");
	size_t n;

	while (true) {
		std::cout << "Выберите способ создание матрицы A и вектора b:" << std::endl;
		std::cout << "1) Автоматический" << std::endl;
		std::cout << "2) Ручной" << std::endl;

		int input_method;
		std::cin >> input_method;

		if ((input_method != 1) & (input_method != 2)) {
			std::cout << "Неверно указан способ создания!!!" << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;
			std::cout << std::endl;
			continue;
		}

		std::cout << std::endl;
		std::cout << "Введите размер матрицы A: ";
		std::cin >> n; 
		
		if (n < 1) {
			std::cout << "Неверно указан размер матрицы!!!" << std::endl;
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
			std::cout << "Введите матрицу A:" << std::endl;
			A = create_hand_matrix(n);
			std::cout << "Введите вектор b:" << std::endl;
			b = create_hand_vector(n);
			x = create_rand_vector(n);
			break;
		default:
			std::cout << "Неверно указан способ создания!!!" << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;
			std::cout << std::endl;
			break;
		}

		double** A_copy = matrix_copy(A, n);
		double* b_copy = vector_copy(b, n);

		std::cout << "Матрица A:" << std::endl;
		print_matrix(A, n);
		std::cout << "Вектор b:" << std::endl;
		print_vector(b, n);

		Gauss(A, b, x, n);
		std::cout << "Вектор x:" << std::endl;
		print_vector(x, n);

		double err = error_Gauss(A_copy, x, b_copy, n);
		std::cout << "Погрешность равна " << err << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << std::endl;

		del_matrix(A, n);
		del_vector(b);
		del_vector(x);
		del_matrix(A_copy, n);
		del_vector(b_copy);
	}
}
