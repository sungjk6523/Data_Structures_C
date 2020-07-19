#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int** make2dArray(int rows, int cols);
int** delete2dArray(int** printArray);
void print2dArray(int** printArray);

int main() {
	int** myArray = NULL;
	myArray = make2dArray(5, 10);
	print2dArray(myArray);
	delete2dArray(myArray);
}

int** make2dArray(int rows, int cols) {
	int** result, i;
	result = (int**)calloc(rows, sizeof(int*));
	for (i = 0; i < rows; i++) 
		result[i] = (int*)calloc(cols, sizeof(int));
	printf("Maked!\n");
	return result;
}

int** delete2dArray(int** delArray) {
	if (!delArray)
		printf("error : Null\n");
	else {
		int size_rows, size_cols, i, j;
		size_rows = _msize(delArray[0]) / 4;
		size_cols = (_msize(delArray) / size_rows) / 4;
		for (i = 0; i < size_rows; i++)
			for (j = 0; j < size_cols; j++)
				delArray[i][j] = NULL;
		free(delArray);
		printf("Freed!\n");
	}
}

void print2dArray(int** printArray) {
	if (!printArray)
		printf("error : Null\n");
	else {
		int size_rows, size_cols, i, j;
		size_cols = _msize(printArray[0]) / 4;
		size_rows = _msize(printArray) / 4;
		
		printf("rows : %d, cols : %d\n", size_rows, size_cols);
		for (i = 0; i < size_rows; i++) {
			for (j = 0; j < size_cols; j++)
				printf("%5d ", printArray[i][j]);
			printf("\n");
		}
	}
}