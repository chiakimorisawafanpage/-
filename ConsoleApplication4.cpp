
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void randMatrix(int** matrix, int rows, int cols) {
	srand(time(0));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = rand() % 100;
		}
	}
}

void sortSpiral(int** matrix, int rows, int cols) {
	int size = rows * cols;
	int* array = new int[size];

	int index = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[index++] = matrix[i][j];
		}
	}
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
	index = 0;

	while (top <= bottom && left <= right)
	{
		for (int i = left; i <= right; i++) 
			matrix[top][i] = array[index++];
			top++;

			for (int i = top; i <= bottom; i++)
				matrix[i][right] = array[index++];
				right--;

				if (top <= bottom)
				{
					for (int i = right; i >= left; i--)
						matrix[bottom][i] = array[index++];
						bottom--;
					
				}
				if (left <= right)
					{
						for (int i = bottom; i >= top; i--)
							matrix[i][left] = array[index++];
							left++;
				}
	}
	delete[] array;
}

void printMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << "\t";
		}
	cout << endl;
	}

}

int main()
{
	int rows, cols;
	cin >> rows >> cols;

	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}

	randMatrix(matrix, rows, cols);
	cout << " " << endl;
	printMatrix(matrix, rows, cols);

	sortSpiral(matrix, rows, cols);
	cout << endl;
	printMatrix(matrix, rows, cols);


	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}
