//
// Created by MD. Zahed on 29/03/2022.
//

#include "mpi.h"
#include <stdio.h>
#include <time.h>


#define INTERVALS 10000000
// 3.141592653589436068273244
#define PI25DT 3.141592653589793238462643


int main (int argc, char *argv[]){

    int rank, pro_size;
    long int i, intervals = INTERVALS;
    double x, dx, f, sum, pi;

    double received_data;


    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &pro_size);

    double time2;
    time_t time1 = clock();


    sum = 0.0;
    dx = 1.0 / (double ) intervals;

    int per_process = intervals / pro_size;
    int left_out = intervals - (pro_size * per_process);

    int start, stop;

    if (rank == pro_size-1) {
        start = intervals;
        //stop = intervals - ((pro_size -2) * per_process);

        if(left_out != 0) {
            stop = intervals - (per_process + left_out);

        } else {
            stop = intervals - per_process;

        }
        //printf("left out %d", left_out);

    } else {
        start = ((rank+1) * per_process);
        stop = (rank * per_process);
    }

    // printf("Start: %d, stop: %d, rank: %d\n", start, stop, rank);



    for (i = start ; i > stop; i--) {
        x = dx * ((double) (i - 0.5));
        f = 4.0 / (1.0 + x*x);
        sum = sum + f;
    }



    pi = dx*sum;

    //printf("Computed PI %.24f, rank: %d\n", pi, rank);

    MPI_Reduce(&pi, &received_data, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        //printf("Computed PI %.24f\n", received_data);
        time2 = (clock() - time1) / (double) CLOCKS_PER_SEC;

        printf("Computed PI %.24f, time: %f\n", received_data, time2);
        printf("Error       %.24f\n\n", PI25DT-received_data);


        //printf("After reduced data: %d in process: %d\n", received_data, rank);

    }







    MPI_Finalize();
    return 0;
}
