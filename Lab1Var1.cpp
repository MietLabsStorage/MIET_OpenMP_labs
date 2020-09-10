#include <iostream>
#include "Lab1Var1.h"
#include <omp.h>

using namespace std;

int countSevensInNum(int num)
{
	int count = 0;
	while (num > 0)
	{
		if (num % 10 == 7)
			count++;
		num /= 10;
	}
	return count;
}

void runLab1v1Lin(int** matrix, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		int sevensSum = 0;
		for (int j = 0; j < M - 1; j++)
		{
			for (int k = j + 1; k < M; k++)
			{
				sevensSum += countSevensInNum(matrix[i][j] + matrix[i][k]);
			}
		}
		//printf("row %d : %d \n", i, sevensSum);
		cout << "row " << i << ": " << sevensSum << endl;
	}
}

void runLab1v1Par(int** matrix, int N, int M)
{
#pragma omp parallel //shared(matrix, N, M) 
	{
		if(omp_get_thread_num() == 0)
			cout << "\t\t\t--threads: " << omp_get_num_threads() << endl;
#pragma omp  for 
		for (int i = 0; i < N; i++)
		{
			int sevensSum = 0;
			for (int j = 0; j < M - 1; j++)
			{
				for (int k = j + 1; k < M; k++)
				{
					sevensSum += countSevensInNum(matrix[i][j] + matrix[i][k]);
				}
			}
			//printf("row %d : %d \n", i, sevensSum);
			cout << "row " << i << ":" << sevensSum << endl;
		}
	}
}