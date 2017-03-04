CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall -fopenmp 
EXECUTABLES = \
	original \
	naivemp \
	syncmp \
	simplemp 

ENABLE_ALL = \
	-DORIGINAL\
	-DNAIVEMP\
	-DSYNCMP\
	-DSIMPLEMP

default : pi_thread.o
	$(CC) $(CFLAGS) pi_thread.o main.c -DORIGINAL -o original
	$(CC) $(CFLAGS) pi_thread.o main.c -DNAIVEMP -o naivemp
	$(CC) $(CFLAGS) pi_thread.o main.c -DSYNCMP -o syncmp
	$(CC) $(CFLAGS) pi_thread.o main.c -DSIMPLEMP -o simplemp
	$(CC) $(CFLAGS) pi_thread.o main.c $(ENABLE_ALL) -o test_all

pi_thread.o : pi_thread.c
	$(CC) -c $(CFLAGS) pi_thread.c -o pi_thread.o

plot : default
	sh scripts/data.sh
	gnuplot scripts/plot.gp

clean : 
	rm -f $(EXECUTABLES) test_all data.txt pi.png *.o
