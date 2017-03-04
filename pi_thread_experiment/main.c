#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

#include "pi_thread.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0
#define STEP 1000000

int main(int argc, char **argv)
{
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};
    int loop = 25;

#if defined NAIVEMP || SYNCMP || SIMPLEMP
    if(argc != 2) {
        printf("EXECUTABLE <thread_number>\n");
        return 1;
    }
    long thread_num = atoi(argv[1]);
#endif

#if defined(ORIGINAL)
    clock_gettime(CLOCK_ID, &start);
    for(int i = 0; i < loop; i++) {
        computepi_orig(STEP);
    }
    clock_gettime(CLOCK_ID, &end);

    printf("%.15lf,", (double)(end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);
#endif

#if defined(NAIVEMP)
    clock_gettime(CLOCK_ID, &start);
    for(int i = 0; i < loop; i++) {
        computepi_naivemp(STEP, thread_num);
    }
    clock_gettime(CLOCK_ID, &end);

    printf("%.15lf,", (double)(end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);
#endif

#if defined(SYNCMP)
    clock_gettime(CLOCK_ID, &start);
    for(int i = 0; i < loop; i++) {
        computepi_sync(STEP, thread_num);
    }
    clock_gettime(CLOCK_ID, &end);

    printf("%.15lf,", (double)(end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);
#endif

#if defined(SIMPLEMP)
    clock_gettime(CLOCK_ID, &start);
    for(int i = 0; i < loop; i++) {
        computepi_simplemp(STEP, thread_num);
    }
    clock_gettime(CLOCK_ID, &end);

    printf("%.15lf,", (double)(end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);
#endif
}
