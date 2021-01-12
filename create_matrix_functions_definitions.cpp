#include <iostream>

#include "create_matrix_functions.hpp"

void create_matrices(Matrix &first, Matrix &second){

	unsigned int input_rows1, input_cols1, input_rows2, input_cols2;
	double elements1, elements2;

	std::cout << "Please enter the number of rows in matrix #1: "; std::cin >> input_rows1;
	std::cout << "Please enter the number of columns in matrix #1: "; std::cin >> input_cols1; std::cout << std::endl;
	std::cout << "Please enter the number of rows in matrix #2: "; std::cin >> input_rows2;
	std::cout << "Please enter the number of columns in matrix #2: "; std::cin >> input_cols2; std::cout << std::endl;

	first.set_rows(input_rows1); first.set_cols(input_cols1); first.matrix.resize(input_rows1);
	second.set_rows(input_rows2); second.set_cols(input_cols2); second.matrix.resize(input_rows2);

	for(unsigned int p{0}; p < first.get_rows(); ++p){
		first.matrix[p].resize(first.get_cols());
	}

	for(unsigned int k{0}; k < second.get_rows(); ++k){
		second.matrix[k].resize(second.get_cols());
	}

	std::cout << "Please enter the elements in matrix #1 separated with spaces. Press enter to move to the next row: "
			<< std::endl;

	for(unsigned int i{0}; i < first.get_rows(); ++i){
		for(unsigned int j{0}; j < first.get_cols(); ++j){
			std::cin >> elements1;
			first.matrix[i][j] = elements1;
		}
	}

	std::cout << "Please enter the elements in matrix #2 separated with spaces. Press enter to move to the next row: "
			<< std::endl;

	for(unsigned int m{0}; m < second.get_rows(); ++m){
		for(unsigned int n{0}; n < second.get_cols(); ++n){
			std::cin >> elements2;
			second.matrix[m][n] = elements2;
		}
	}

}

void create_matrix(Matrix &matrix){

	unsigned int input_rows, input_cols;
	double elements;

	std::cout << "Please enter the number of rows in the matrix: "; std::cin >> input_rows;
	std::cout << "Please enter the number of columns in the matrix: "; std::cin >> input_cols; std::cout << std::endl;

	matrix.set_rows(input_rows); matrix.set_cols(input_cols); matrix.matrix.resize(input_rows);

	for(unsigned int k{0}; k < matrix.get_rows(); ++k){
		matrix.matrix[k].resize(matrix.get_cols());
	}

	std::cout << "Please enter the elements in the matrix separated with spaces. Press enter to move to the next row: "
			<< std::endl;

	for(unsigned int i{0}; i < matrix.get_rows(); ++i){
		for(unsigned int j{0}; j < matrix.get_cols(); ++j){
			std::cin >> elements;
			matrix.matrix[i][j] = elements;
		}
	}

}



