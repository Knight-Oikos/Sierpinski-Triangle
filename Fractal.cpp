#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void SierpenskiTriangle(int size, char **arr, int x, int y);

int main() {
	int size;
	int actualSize = 1;
	int row, col, i, j;
	int boardSize;


	cout << "Enter the number of recursions (recommended max is '8')\n"; 
	cin >> size;

	for (i = 0; i <= size; ++i) {
		actualSize = actualSize * 2;
	}
	
	boardSize = actualSize * 2;
	
	char **drawingBoard = new char*[boardSize];
	
	for (int cell = 0; cell < boardSize; ++cell) {
		drawingBoard[cell] = new char[boardSize];
	}
 
	SierpenskiTriangle(actualSize, drawingBoard, 0, 0);

	for (row = 0; row < actualSize; ++row) {
		for (col = 0; col < actualSize * 2; ++col) {
			cout << drawingBoard[row][col];
		}
		cout << endl;
	}
	
	for (int cell = 0; cell < boardSize; ++cell) {
		delete[] drawingBoard[cell];
	}

	delete[] drawingBoard;
	return 0; 
}

void SierpenskiTriangle(int size, char **arr, int x, int y) {
	int row;
	int col;
	int space;
	int i; // i is a space index to determine the number of spaces

	row = x;

	for (i = 0; i < size; ++i) {

		col = y;
		for (space = 0; space < size - i - 1; ++space) {
			arr[row][col] = ' ';
			++col;
		} 

		arr[row][col] = '/';
			
		++col;

		for (space = 0; space < i * 2; ++space) {
			if (i == size - 1) {
				arr[row][col] = '_';
			}
			else {
				arr[row][col] = ' ';
			}
			++col;
		}
		
		arr[row][col] = '\\';

		++row;
	}
	
	if (size != 2) {
		SierpenskiTriangle(size / 2, arr, x, y + size / 2); // top
		SierpenskiTriangle(size / 2, arr, x + size / 2, y); // left
		SierpenskiTriangle(size / 2, arr, x + size / 2, y + size); // right side
	}
}
