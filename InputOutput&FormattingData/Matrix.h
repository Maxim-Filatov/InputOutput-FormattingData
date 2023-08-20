#pragma once

const int SIZE = 6;

class Matrix {
	private:
		int matrix[SIZE][SIZE];
		// Strating value for the matrix generation in the loop
		int startValue;

	public:
		int size = SIZE - 1;

		Matrix(int startValue);
		void generate();
		void print();
};
