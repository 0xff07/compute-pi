#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#include "pi_thread.h"

double computepi_orig(int step)
{
    double pi = 0;
    double dx = 1.0 / step;
    for(int i = 0; i < step; i++) {
        double x = i * dx;
        pi += dx / (1 + x*x);
    }
    return pi*4;
}

double computepi_naivemp(int step, int thread)
{
    //double *pi = calloc(thread, sizeof(double));
    double pi[1024] = {0};
    double dx = 1.0 / step;

    int real_thrd = 0;
    omp_set_num_threads(thread);
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        real_thrd = omp_get_num_threads();
        for(int i = id; i < step; i += real_thrd) {
            double x = i * dx;
            pi[id] += dx / (1 + x*x);
        }
    }

    double sum = 0;
    for(int i = 0; i < real_thrd; i++) {
        sum += pi[i];
    }

    //free(pi);
    return sum * 4;
}

double computepi_sync(int step, int thread)
{
    double pi = 0;
    double dx = 1.0 / step;

    int real_thrd = 0;
    omp_set_num_threads(thread);
    #pragma omp parallel
    {
        double sum = 0;
        int id = omp_get_thread_num();
        real_thrd = omp_get_num_threads();
        for(int i = id; i < step; i += real_thrd) {
            double x = i * dx;
            sum += dx / (1 + x*x);
        }
        #pragma omp critical
        {
            pi += sum;
        }
    }
    return pi * 4;
}

double computepi_simplemp(int step, int thread)
{
    double pi = 0;
    double dx = 1.0 / step;

    omp_set_num_threads(thread);
    #pragma omp parallel for reduction(+:pi)
    for(int i = 0; i < step; i++) {
        double x = i * dx;
        pi += dx / (1 + x*x);
    }
    return pi*4;
}
