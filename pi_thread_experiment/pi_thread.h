#ifndef PI_THREAD_H
#define PI_THREAD_H

double computepi_orig(int step);
double computepi_naivemp(int step, int thread);
double computepi_sync(int step, int thread);
double computepi_simplemp(int step, int thread);

#endif
