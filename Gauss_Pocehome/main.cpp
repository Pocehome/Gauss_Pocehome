#include <iostream>
#include <locale>
#include "MatrixTools.hpp"

int main() {
	setlocale(LC_CTYPE, "Russian");
	size_t n;

	while (true) {
		std::cout << "�������� ������ �������� ������� A � ������� b:" << std::endl;
		std::cout << "1) ��������������" << std::endl;
		std::cout << "2) ������" << std::endl;

		int input_method;
		std::cin >> input_method;

		if ((input_method != 1) & (input_method != 2)) {
			std::cout << "������� ������ ������ ��������!!!" << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;
			std::cout << std::endl;
			continue;
		}

		std::cout << std::endl;
		std::cout << "������� ������ ������� A: ";
		std::cin >> n; 
		
		if (n < 1) {
			std::cout << "������� ������ ������ �������!!!" << std::endl;
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
			std::cout << "������� ������� A:" << std::endl;
			A = create_hand_matrix(n);
			std::cout << "������� ������ b:" << std::endl;
			b = create_hand_vector(n);
			x = create_rand_vector(n);
			break;
		default:
			std::cout << "������� ������ ������ ��������!!!" << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;
			std::cout << std::endl;
			break;
		}

		double** A_copy = matrix_copy(A, n);
		double* b_copy = vector_copy(b, n);

		std::cout << "������� A:" << std::endl;
		print_matrix(A, n);
		std::cout << "������ b:" << std::endl;
		print_vector(b, n);

		Gauss(A, b, x, n);
		std::cout << "������ x:" << std::endl;
		print_vector(x, n);

		double err = error_Gauss(A_copy, x, b_copy, n);
		std::cout << "����������� ����� " << err << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << std::endl;

		del_matrix(A, n);
		del_vector(b);
		del_vector(x);
		del_matrix(A_copy, n);
		del_vector(b_copy);
	}
}
