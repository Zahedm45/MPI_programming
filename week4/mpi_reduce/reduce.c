//
// Created by MD. Zahed on 29/03/2022.
//


#include "mpi.h"
#include <stdio.h>


int main (int argc, char *argv[]){

    int rank;
    int data = 0;
    int  reduced_data = 0;


    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);




    data = rank;

    if (rank == 0) {
        printf("Before reduced data: %d in process: %d\n", reduced_data, rank);
    }

    MPI_Reduce(&data, &reduced_data, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("After reduced data: %d in process: %d\n", reduced_data, rank);
    }





    MPI_Finalize();
    return 0;
}






