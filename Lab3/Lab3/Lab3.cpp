#include <omp.h>
#include <iostream>
#include <time.h>

#include "Matrix.h"

using namespace std;

//number of elements
//const long long N = 20;
const long long N = 50000000;

int main()
{
	srand(time(0));

	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[N];

	//pack arrays
	for (int k = 0; k < N; k++)
	{
		A[k] = rand() % 2 + 1;
		B[k] = rand() % 2 + 1;
		C[k] = rand() % 2 + 1;
	}
	cout << "Max num procs: " << omp_get_num_procs() << endl;
	cout << "Number of elements: " << N << endl << endl;

	//Reduction code
	double multiply = 1;
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
	//end of reduction code


	//Atomic code
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
	//end of atomic code


	//Critical section code
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
			}
		}
	}
	end = omp_get_wtime();
	cout << "Parallel critical section: " << (end - start) << "   Result :" << multiply << endl;
	//end of critical section code


	//Linear code
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
	//end of linear code


	//Section (2 section) code 
	multiply = 1;
	start = omp_get_wtime();
#pragma omp parallel sections reduction(*:multiply) 
	{
#pragma omp section
		for (int i = 0; i < N / 2; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 2; i < N; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
	}
	end = omp_get_wtime();
	cout << "2 sections: " << (end - start) << "   Result :" << multiply << endl;
	//end of 2 sections code



	//Section (3 section) code 
	multiply = 1;
	start = omp_get_wtime();
#pragma omp parallel sections reduction(*:multiply) 
	{
#pragma omp section
		for (int i = 0; i < N / 3; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 3; i < N / 3 * 2; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 3 * 2; i < N; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
	}
	end = omp_get_wtime();
	cout << "3 sections: " << (end - start) << "   Result :" << multiply << endl;
	//end of 3 sections code


	//Section (4 section) code 
	multiply = 1;
	start = omp_get_wtime();
#pragma omp parallel sections reduction(*:multiply) 
	{
#pragma omp section
		for (int i = 0; i < N / 4; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 4; i < N / 4 * 2; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 4 * 2; i < N / 4 * 3; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 4 * 3; i < N; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
	}
	end = omp_get_wtime();
	cout << "4 sections: " << (end - start) << "   Result :" << multiply << endl;
	//end of 4 sections code


	//Section (8 section) code 
	multiply = 1;
	start = omp_get_wtime();
#pragma omp parallel sections reduction(*:multiply) 
	{
#pragma omp section
		for (int i = 0; i < N / 8; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 8; i < N / 8 * 2; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 8 * 2; i < N / 8 * 3; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 8 * 3; i < N / 8 * 4; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 8 * 4; i < N / 8 * 5; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 8 * 5; i < N / 8 * 6; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 8 * 6; i < N / 8 * 7; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
#pragma omp section
		for (int i = N / 8 * 7; i < N; i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				multiply *= tempMult;
			}
		}
	}
	end = omp_get_wtime();
	cout << "8 sections: " << (end - start) << "   Result :" << multiply << endl;
	//end of 8 sections code

	//Semaphore code
	omp_lock_t lock;
	omp_init_lock(&lock);
	multiply = 1;
	start = omp_get_wtime();
#pragma omp parallel for
	for (int i = 0; i < N; i++)
	{
		int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
		if (tempMult)
		{
			omp_set_lock(&lock);
			multiply *= tempMult;
			omp_unset_lock(&lock);
		}
	}
	end = omp_get_wtime();
	omp_destroy_lock(&lock);
	cout << "Semaphore: " << (end - start) << "   Result :" << multiply << endl;
	//end of semaphore code


	//Barrier code
	multiply = 1;
	double* beforeBarrierMultiply = new double[omp_get_max_threads()];
	for (int i = 0; i < omp_get_max_threads(); i++) {
		beforeBarrierMultiply[i] = 1;
	}
	start = omp_get_wtime();
#pragma omp parallel
	{
		int num = omp_get_thread_num();
		for (int i = (num)*N / omp_get_num_threads(); i < (num + 1) * N / omp_get_num_threads(); i++)
		{
			int tempMult = A[i] % 2 == 0 ? B[i] / C[i] : B[i] + C[i];
			if (tempMult)
			{
				beforeBarrierMultiply[num] *= tempMult;
			}
		}
#pragma omp barrier

#pragma omp master
		{
			for (int i = 0; i < omp_get_num_threads(); i++) {
				multiply *= beforeBarrierMultiply[i];
			}
		}
	}
	end = omp_get_wtime();

	cout << "Barrier: " << (end - start) << "   Result :" << multiply << endl;
	//end of barrier code

	return 0;

}