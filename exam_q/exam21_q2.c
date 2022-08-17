//
// Created by MD. Zahed on 14/08/2022.
//


#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]){

    int rank;
    int rank_size;
    int *buf = NULL;

    int ITERATIONS = 100000;
    int A[3];
    int B[ITERATIONS];
    int D[ITERATIONS];



    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &rank_size);
    int root_rank = rank_size -1;

    int reminder = ITERATIONS % rank_size;
    int iteration_per_rank = (ITERATIONS - reminder) / rank_size;



    int i = iteration_per_rank * rank + 1;
    int k = i + iteration_per_rank;
    int *send_data;

    if (rank == root_rank) {

        buf = (int*) malloc(sizeof(int) * ITERATIONS);
        k += reminder;
        send_data = (int *) malloc(sizeof (int) * iteration_per_rank + reminder);

    } else {
        send_data = (int *) malloc(sizeof (int) *iteration_per_rank);
    }





    int n = 0;
    while (i <= k) {
        send_data[0] = 0;
        for(int j = 0; j<3; j++){
            send_data[n] += A[j] * B[i -1 + j];
        }

        i++;
        n++;
    }


    MPI_Gather(&send_data, iteration_per_rank, MPI_INT, buf, iteration_per_rank, MPI_INT, root_rank, MPI_COMM_WORLD);


    if (rank == root_rank) {

        for ( i = 0; i < ITERATIONS; ++i) {
            printf(" %d", buf[i]);
        }
        printf("\n");
    }



    MPI_Finalize();
    return 0;
}
