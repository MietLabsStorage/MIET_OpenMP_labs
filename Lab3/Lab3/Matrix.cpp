#include <iostream>
#include "Matrix.h"

using namespace std;

void matrixInit(int** matrix, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			matrix[i][j] = rand() % 9 + 1;
	}
}

void matrixShow(int** matrix, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}