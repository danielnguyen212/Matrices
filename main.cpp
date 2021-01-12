#include <iostream>

#include "Matrix.hpp"
#include "create_matrix_functions.hpp"

int main(){

	bool running{true};

	Matrix A{0, 0};
	Matrix B{0, 0};
	Matrix C{0, 0};

	std::cout << "WELCOME TO THE MATRIX PROGRAM!" << "\n" << "==============================" << "\n";

	while(running){
		int user_input;
		std::cout << "1) Add two matrices" << "\n" << "2) Subtract two matrices" << "\n" << "3) Multiply two matrices" << "\n" <<
					"4) Multiply a matrix by a scalar" << "\n" << "5) Find the transpose of a matrix" << "\n"
					<< "6) Sort a matrix in ascending order" << "\n" << "7) Check if a matrix contains a saddle point" << "\n"
					<< "8) Return the determinant of a matrix" << "\n" << "9) Check if a matrix is invertible" << "\n"
					<< "10) Exit" << "\n";
		std::cout << "\n" <<"What would you like to do? Please enter a number: "; std::cin >> user_input; std::cout << "\n";

		if(user_input == 1){
			create_matrices(A, B);
			if((A.get_rows() == B.get_rows()) && (A.get_cols() == B.get_cols())){
				std::cout << "\n" << "The resulting matrix is: " << "\n\n";
				(A + B).print_matrix(); std::cout << "\n";
			}
			else{
				std::cout << "\n" << "Cannot compute. The dimensions of both matrices have to be the same." << "\n\n";
			}
		}
		else if(user_input == 2){
			create_matrices(A, B);
			if((A.get_rows() == B.get_rows()) && (A.get_cols() == B.get_cols())){
				std::cout << "\n" << "The resulting matrix is: " << "\n\n";
				(A - B).print_matrix(); std::cout << "\n";
			}
			else{
				std::cout << "\n" << "Cannot compute. The dimensions of both matrices have to be the same." << "\n\n";
			}
		}
		else if(user_input == 3){
			create_matrices(A, B);
			if(A.get_cols() == B.get_rows()){
				std::cout << "\n" << "The resulting matrix is: " << "\n\n";
				(A * B).print_matrix(); std::cout << "\n";
			}
			else{
				std::cout << "\n" << "Cannot compute. The number of columns in the first matrix have to be the same as "
						"the number of rows in the second matrix." << "\n\n";
			}
		}
		else if(user_input == 4){
			double constant;
			create_matrix(C);
			std::cout << "Please enter the value of the scalar: "; std::cin >> constant;
			std::cout << "\n" << "The resulting matrix is: " << "\n\n";
			(C * constant).print_matrix(); std::cout << "\n";
		}
		else if(user_input == 5){
			create_matrix(C);
			std::cout << "\n" << "The resulting matrix is: " << "\n\n";
			(C.transpose()).print_matrix(); std::cout << "\n";
		}
		else if(user_input == 6){
			create_matrix(C);
			std::cout << "\n" << "The resulting matrix is: " << "\n\n";
			(C.sort_matrix()).print_matrix(); std::cout << "\n";
		}
		else if(user_input == 7){
			create_matrix(C);
			if(C.has_saddle_point()){
				std::cout << "\n" << "The matrix contains a saddle point." << "\n\n";
			}
			else{
				std::cout<< "\n" << "The matrix does not contain a saddle point." << "\n\n";
			}
		}
		else if(user_input == 8){
			create_matrix(C);
			if(C.get_rows() == C.get_cols()){
				std::cout << "\n" << "The determinant of the matrix is: " << C.calculate_determinant(C.matrix, C.get_rows()) << "\n\n";
			}
			else{
				std::cout << "\n" << "Cannot determine. The number of rows have to be the same as the number of columns." << "\n\n";
			}
		}
		else if(user_input == 9){
			create_matrix(C);
			if(C.get_rows() == C.get_cols()){
				if(C.is_invertible()){
					std::cout << "\n" << "The matrix is invertible." << "\n\n";
				}
				else{
					std::cout<< "\n" << "The matrix is not invertible." << "\n\n";
				}
			}
			else{
				std::cout << "\n" <<"Cannot determine. The number of rows have to be the same as the number of columns." << "\n\n";
			}
		}
		else if(user_input == 10){
			std::cout << "===== PROGRAM TERMINATED =====";
			running = false;
		}
		else{
			std::cout << "That is not a valid number. Please try again." << "\n\n";
		}
	}

	return 0;

}


