
//
// Created by MD. Zahed on 03/03/2022.
//

#include "mpi.h"
#include <stdio.h>


int main (int argc, char *argv[]){

    int rank;
    int data = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 1) {
        data = 10;
    }

    printf("Before Broad cast data in process %d, Data: %d\n", rank, data);

    MPI_Bcast(&data, 1, MPI_INT, 1, MPI_COMM_WORLD);
    printf("After Broad cast data in process %d, Data: %d\n", rank, data);

    MPI_Finalize();
    return 0;
}







