#include <omp.h>
#include <iostream>
#include <time.h>

#include "Matrix.h"

using namespace std;

const long long N = 1000000;

int main()
{
	srand(time(0));

	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[N];

	for (int k = 0; k < N; k++)
	{
		A[k] = rand() % 10;
		B[k] = rand() % 10;
		C[k] = rand() % 9 + 1;
	}

	long long multiply = 1;
	double start, end;
	start = omp_get_wtime();
#pragma omp parallel for reduction(*: multiply)
	for (int i = 0; i < N; i++)
	{
		int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
		if (tempMult)
		{
			multiply *= tempMult;
		}
	}
	end = omp_get_wtime();
	cout << "Parallel reduct: " << (end - start) << "   Result :" << multiply << endl;


	multiply = 1;
	start = omp_get_wtime();
#pragma omp parallel for
	for (int i = 0; i < N; i++)
	{
		int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
		if (tempMult)
		{
#pragma omp atomic
			multiply *= tempMult;
		}
	}
	end = omp_get_wtime();
	cout << "Parallel atomic: " << (end - start) << "   Result :" << multiply << endl;

	multiply = 1;
	start = omp_get_wtime();
#pragma omp parallel for
	for (int i = 0; i < N; i++)
	{
		int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
		if (tempMult)
		{
#pragma omp critical (name)
			{
				multiply *= tempMult;
				multiply += 1;
			}
#pragma omp critical (name)
			{
				multiply *= tempMult;
				multiply -= 1;
			}

		}
	}
	end = omp_get_wtime();
	cout << "Parallel section: " << (end - start) << "   Result :" << multiply << endl;

	multiply = 1;
	start = omp_get_wtime();
	for (int i = 0; i < N; i++)
	{
		int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
		if (tempMult)
		{
			multiply *= tempMult;
		}
	}
	end = omp_get_wtime();
	cout << "Linear: " << (end - start) << "   Result :" << multiply << endl;


	return 0;
}