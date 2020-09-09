#include <omp.h>
#include <iostream>
#include <time.h>

#include "Matrix.h"
#include "Lab1Lin.h"

using namespace std;

int main()
{
	srand(time(0));

	int N[5] = { 3, 10, 100, 100, 150 };
	int M[5] = { 3, 10, 100, 10, 10 };

	for (int k = 0; k < 1; k++)
	{
		/*create matrix*/
		printf("N = %d   M = %d\n", N[k], M[k]);
		int** matrix = new int* [N[k]];
		for (int i = 0; i < N[k]; i++)
		{
			matrix[i] = new int[M[k]];
		}
		matrixInit(matrix, N[k], M[k]);
		if(N[k] < 10 && M[k] < 10)
			matrixShow(matrix, N[k], M[k]);



		int start1, end1;
		start1 = clock();
		//runLab1Var0(matrix, N[k], M[k]);
		runLab1Var1(matrix, N[k], M[k]);
		end1 = clock();

	}
	return 0;
}