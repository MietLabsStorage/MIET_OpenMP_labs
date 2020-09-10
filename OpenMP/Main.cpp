#include <omp.h>
#include <iostream>
#include <time.h>

#include "Matrix.h"
#include "Lab1Var0.h"
#include "Lab1Var1.h"

using namespace std;

int main()
{
	srand(time(0));

	int N[5] = { 3, 10, 100, 100, 150 };
	int M[5] = { 3, 10, 100, 10, 10 };

	for (int k = 0; k < 5; k++)
	{
		/*create matrix*/
		printf("N = %d   M = %d\n", N[k], M[k]);
		int** matrix = new int* [N[k]];
		for (int i = 0; i < N[k]; i++)
		{
			matrix[i] = new int[M[k]];
		}
		matrixInit(matrix, N[k], M[k]);
		if (N[k] < 5 && M[k] < 5)
		{
			cout << "--MATRIX--" << endl;
			matrixShow(matrix, N[k], M[k]);
		}



		int startLin, endLin;
		cout << "\t\t\t--LINEAR--\n";
		startLin = clock();
		//runLab1Var0(matrix, N[k], M[k]);
		runLab1v1Lin(matrix, N[k], M[k]);
		endLin = clock();

		cout << "\t\t\t--Parallel--\n";
		int startPar, endPar;
		startPar = clock();
		//runLab1Var0(matrix, N[k], M[k]);
		runLab1v1Par(matrix, N[k], M[k]);
		endPar = clock();

		cout << "\t\t\t--TIME FOR " << N[k] << "*" << M[k] << " MATRIX--" << endl;
		cout << "Linear time:   " << (endLin - startLin) * 1000 / CLOCKS_PER_SEC << " msec\n";
		cout << "Parallel time: " << (endPar - startPar) * 1000 / CLOCKS_PER_SEC << " msec\n";
	}
	return 0;
}