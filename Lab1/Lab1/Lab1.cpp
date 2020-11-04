#include <omp.h>
#include <iostream>
#include <time.h>

#include "Matrix.h"
#include "Lab1Var1.h"

using namespace std;

int main()
{
	srand(time(0));

	int N[5] = { 3, 10000, 20 };
	int M[5] = { 3, 20, 10000 };

	for (int k = 0; k < 3; k++)
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



		double startLin, endLin;
		cout << "\t\t\t--LINEAR--\n";
		startLin = omp_get_wtime();
		//runLab1Var0(matrix, N[k], M[k]);
		runLab1v1Lin(matrix, N[k], M[k]);
		endLin = omp_get_wtime();

		cout << "\t\t\t--Parallel--\n";
		double startPar, endPar;
		startPar = omp_get_wtime();
		//runLab1Var0(matrix, N[k], M[k]);
		runLab1v1Par(matrix, N[k], M[k]);
		endPar = omp_get_wtime();

		cout << "\t\t\t--TIME FOR " << N[k] << "*" << M[k] << " MATRIX--" << endl;
		cout << "Linear time:   " << (endLin - startLin) << " sec\n";
		cout << "Parallel time: " << (endPar - startPar) << " sec\n";
	}
	return 0;
}