// Generation of a matrix according to the individual number
#include "Matrix.h"
#include <iostream>

using namespace std;

// Constructor with parameter
Matrix::Matrix(int startValue) {
	this->startValue = startValue;
}

// Matrix generation
void Matrix::generate() {
	int row = size;
	int col = 0;
	int val = startValue;
	for (int i = size; i >= 0; i--) {
		for (int j = 0; j <= size; j++) {
			if ((i == row) && (j == col)) {
				matrix[row--][col++] = val++;
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}
}

void Matrix::print() {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
