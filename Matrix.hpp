#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

class Matrix{

public:
	Matrix(unsigned int num_rows, unsigned int num_cols);

	std::vector<std::vector<double>> matrix;

	Matrix operator+(Matrix const &other);

	Matrix operator-(Matrix const &other);

	Matrix operator*(Matrix const &other);

	Matrix operator*(double const &scalar);

	Matrix transpose();

	Matrix sort_matrix();

	unsigned int get_rows();

	unsigned int get_cols();

	void set_rows(unsigned int num_of_rows);

	void set_cols(unsigned int num_of_cols);

	bool has_saddle_point();

	double calculate_determinant(std::vector<std::vector<double>> input_matrix, unsigned int size);

	bool is_invertible();

	void print_matrix();

private:
	unsigned int rows;

	unsigned int cols;

};

#endif



