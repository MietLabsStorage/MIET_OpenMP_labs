#include <omp.h>
#include <iostream>
using namespace std;
const int NMAX[5] = { 100, 100, 15000, 15000, 100 };
const int LIMIT[5] = { 10, 200, 100, 150000, 333 };
void main()
{
    double times[5];
    int threadscount[5];
    setlocale(LC_ALL, "Rus");
    for (int k = 0; k < 5; k++)
    {
        int i, j;
        float sum;
        float** a = new float* [NMAX[k]];
        for (int i = 0; i < NMAX[k]; i++)
            a[i] = new float[NMAX[k]];

        for (i = 0; i < NMAX[k]; i++)
            for (j = 0; j < NMAX[k]; j++)
                a[i][j] = i + j;
        double timeStart, timeEnd;
        timeStart = omp_get_wtime();
#pragma omp parallel shared(a) if (NMAX[k]>LIMIT[k])
        {
            threadscount[k] = omp_get_num_threads();
#pragma omp for private(i,j,sum) 
            for (i = 0; i < NMAX[k]; i++)
            {
                sum = 0;
                for (j = 0; j < NMAX[k]; j++)
                    sum += a[i][j];
                printf("Сумма элементов строки %d равна %f\n", i, sum);
            }
        } /* Завершение параллельного фрагмента */
        timeEnd = omp_get_wtime();
        times[k] = timeEnd - timeStart;

    }
    for (int k = 0; k < 5; k++)
    {
        cout << "NMAX=" << NMAX[k] << "\tLIMIT=" << LIMIT[k] << "\ttime=" << times[k] << "\tthreads=" << threadscount[k] << endl;
    }
}

