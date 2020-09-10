#include <iostream>
#include "Lab1Var1.h"

using namespace std;

//Дана матрица из MxN натуральных (ненулевых) элементов (задаются случайно).
//Написать программу, считающую количество семёрок 
//в десятеричной записи числа всех попарных сумм элементов для каждой строки.
int countSevensInNum(int num)
{
	int count = 0;
	while (num > 0)
	{
		if(num % 10 == 7)
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
		printf("row %d : %d \n", i, sevensSum);
	}
}

void runLab1v1Par(int** matrix, int N, int M)
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
		printf("row %d : %d \n", i, sevensSum);
	}
}