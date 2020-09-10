#include <iostream>
#include "Lab1Var0.h"

using namespace std;


//Дана матрица из MxN натуральных(ненулевых) элементов(задаются случайно).
//Написать программу, считающую сумму единиц в бинарной записи числа всех 
//попарных произведений элементов для каждой строки.
int dexToBinOnesSum(int dexNum)
{
	int binSum = 0;
	while (dexNum >= 1)
	{
		binSum += dexNum % 2;
		dexNum /= 2;
	}
	return binSum;
}

void runLab1v0Lin(int** matrix, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		int onesSum = 0;
		for (int j = 0; j < M - 1; j++)
		{
			for (int k = j + 1; k < M; k++)
			{
				onesSum += dexToBinOnesSum(matrix[i][j] * matrix[i][k]);
			}
		}
		printf("row %d : %d \n", i, onesSum);
	}
}

void runLab1v0Par(int** matrix, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		int onesSum = 0;
		for (int j = 0; j < M - 1; j++)
		{
			for (int k = j + 1; k < M; k++)
			{
				onesSum += dexToBinOnesSum(matrix[i][j] * matrix[i][k]);
			}
		}
		printf("row %d : %d \n", i, onesSum);
	}
}