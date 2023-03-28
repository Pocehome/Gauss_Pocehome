#pragma once

void Gauss(double** A, double* b, double* x, size_t n);

double** create_rand_matrix(size_t n);
double** create_hand_matrix(size_t n);

double* create_rand_vector(size_t n);
double* create_hand_vector(size_t n);

void print_matrix(double** matrix, size_t n);
void print_vector(double* vector, size_t n);

double* mult_matrix_vector(double** matrix, double* vector, size_t n);

double* vector_copy(double* vector, size_t n);
double** matrix_copy(double** matrix, size_t n);

void del_vector(double* vector);
void del_matrix(double** matrix, size_t n);

double error_Gauss(double** A, double* x, double* b, size_t n);