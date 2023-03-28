#pragma once

void Gauss(double** A, double* b, double* x, size_t n);
void matrix_rand_fill(double** matrix, size_t n);
void matrix_hand_fill(double** matrix, size_t n);
void vector_rand_fill(double* vector, size_t n);
void vector_hand_fill(double* vector, size_t n);
double** create_rand_matrix(size_t n);
double** create_hand_matrix(size_t n);
double* create_rand_vector(size_t n);
double* create_hand_vector(size_t n);
void print_matrix(double** matrix, size_t n);
void print_vector(double* vector, size_t n);