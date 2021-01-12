#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>

#include "Matrix.hpp"

Matrix::Matrix(unsigned int num_rows, unsigned int num_cols):
rows{num_rows},
cols{num_cols}{

	matrix.resize(num_rows);
	for(unsigned int i{0}; i < num_rows; ++i){
		matrix[i].resize(num_cols);
	}

}

unsigned int Matrix::get_rows(){

	return this->rows;

}

unsigned int Matrix::get_cols(){

	return this->cols;

}

void Matrix::set_rows(unsigned int num_of_rows){

	rows = num_of_rows;

}
void Matrix::set_cols(unsigned int num_of_cols){

	cols = num_of_cols;

}

Matrix Matrix::operator+(Matrix const &other){

	Matrix sum_matrix(this->rows, this->cols);

	for(unsigned int i{0}; i < this->rows; ++i){
		for(unsigned int j{0}; j < this->cols; ++j){
			sum_matrix.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
		}
	}

	return sum_matrix;

}

Matrix Matrix::operator-(Matrix const &other){

	Matrix difference_matrix(this->rows, this->cols);

	for(unsigned int i{0}; i < this->rows; ++i){
		for(unsigned int j{0}; j < this->cols; ++j){
			difference_matrix.matrix[i][j] = this->matrix[i][j] - other.matrix[i][j];
		}
	}

	return difference_matrix;

}

Matrix Matrix::operator*(Matrix const &other){

	Matrix multiply_matrix(this->rows, other.cols);

	for(unsigned int i{0}; i < this->rows; ++i){
		for(unsigned int j{0}; j < other.cols; ++j){
			double sum{0.0};
			for(unsigned int k{0}; k < this->cols; ++k){
				sum = sum + this->matrix[i][k] * other.matrix[k][j];
				multiply_matrix.matrix[i][j] = sum;
			}
		}
	}

	return multiply_matrix;

}

Matrix Matrix::operator*(double const &scalar){

	Matrix scalar_matrix(this->rows, this->cols);

	for(unsigned int i{0}; i < this->rows; ++i){
		for(unsigned int j{0}; j < this->cols; ++j){
			scalar_matrix.matrix[i][j] = this->matrix[i][j] * scalar;
		}
	}

	return scalar_matrix;

}

Matrix Matrix::transpose(){

	Matrix transpose_matrix(this->cols, this->rows);

	for(unsigned int i{0}; i < this->cols; ++i){
		for(unsigned int j{0}; j < this->rows; ++j){
			transpose_matrix.matrix[i][j] = this->matrix[j][i];
		}
	}

	return transpose_matrix;

}

Matrix Matrix::sort_matrix(){

	Matrix sorted_matrix(this->rows, this->cols);

	for(unsigned int i{0}; i < this->rows; ++i){
		for(unsigned int j{0}; j < this->cols; ++j){
			sorted_matrix.matrix[i][j] = this->matrix[i][j];
		}
	}
	std::vector<double> tmp_matrix;
	tmp_matrix.resize(sorted_matrix.rows * sorted_matrix.cols);

	for(unsigned int m{0}; m < sorted_matrix.rows; ++m){
		for(unsigned int n{0}; n < sorted_matrix.cols; ++n){
			tmp_matrix[n + sorted_matrix.cols * m] = sorted_matrix.matrix[m][n];
		}
	}
	std::sort(tmp_matrix.begin(), tmp_matrix.end());

	for(unsigned int p{0}; p < sorted_matrix.rows; ++p){
		for(unsigned int k{0}; k < sorted_matrix.cols; ++k){
			sorted_matrix.matrix[p][k] = tmp_matrix[k + sorted_matrix.cols * p];
		}
	}

	return sorted_matrix;

}

bool Matrix::has_saddle_point(){

	for(unsigned int i{0}; i < this->rows; ++i){
		unsigned int col_index{0};
		unsigned int count{0};
		for(unsigned int j{0}; j < (this->cols - 1); ++j){
			if(this->matrix[i][j + 1] < this->matrix[i][j]){
				col_index = j + 1;
			}
		}
		for(unsigned int m{0}; m < this->rows; ++m){
			for(unsigned int n{0}; n < this->cols; ++n){
				if(this->matrix[m][n] < this->matrix[i][col_index]){
					if(n == col_index){
						++count;
					}
				}
			}
		}
		if(count == (this->rows - 1)){
			return true;
		}
	}
		return false;

}

double Matrix::calculate_determinant(std::vector<std::vector<double>> input_matrix, unsigned int size){

	double determinant{0.0};

	if(size == 1){
		determinant = input_matrix[0][0];
		return determinant;
	}
	else if(size == 2){
		determinant = input_matrix[0][0] * input_matrix[1][1] - input_matrix[0][1] * input_matrix[1][0];
		return determinant;
	}
	else{
		std::vector<std::vector<double>> submatrix;
		submatrix.resize(size);

		for(unsigned int i{0}; i < size; ++i){
			submatrix[i].resize(size);
		}

		for(unsigned int k{0}; k < size; ++k){
			unsigned int sub_m{0};
			for(unsigned int m{1}; m < size; ++m){
				unsigned int sub_n{0};
				for(unsigned int n{0}; n < size; ++n){
					if(n == k){
						continue;
					}
					submatrix[sub_m][sub_n] = input_matrix[m][n];
					++sub_n;
				}
				++sub_m;
			}

			determinant = determinant + input_matrix[0][k] * pow(-1, k) * calculate_determinant(submatrix, size - 1);
		}

		return determinant;
	}
}

bool Matrix::is_invertible(){

	if(calculate_determinant(this->matrix, this->rows) != 0){
		return true;
	}
	else{
		return false;
	}

}

void Matrix::print_matrix(){

	for(unsigned int i{0}; i < this->rows; ++i){
		for(unsigned int j{0}; j < this->cols; ++j){
			std::cout << std::right << std::setw(5) << std::right << this->matrix[i][j];
		}

		std::cout << std::endl;
	}

}


