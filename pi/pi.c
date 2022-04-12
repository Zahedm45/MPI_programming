//
// Created by MD. Zahed on 29/03/2022.
//

#include "mpi.h"
#include <stdio.h>

#define INTERVALS 10000000


int main (int argc, char *argv[]){

    int rank, size;
    long int i, intervals = INTERVALS;
    double x, dx, f, sum, pi;




/*    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);*/




    sum = 0.0;
    dx = 1.0 / (double ) intervals;

    int per_process = intervals / size;
    int left_out = intervals - (size * per_process);

    for (i = intervals; i >= 1; i--) {
        x = dx * ((double) (i - 0.5));
        f = 4.0 / (1.0 + x*x);
        sum = sum + f;
    }

    pi = dx*sum;

    printf("Computed PI %.24f\n", pi);






    //MPI_Finalize();
    return 0;
}
