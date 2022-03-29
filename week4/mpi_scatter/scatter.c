//
// Created by MD. Zahed on 29/03/2022.
//

#include "mpi.h"
#include <stdio.h>


int main (int argc, char *argv[]){

    int rank;
    int data = 0;
    int *buf = NULL;


    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);








    if (rank == 0) {
        int arr[4] = {1, 2, 3, 4};
        buf = arr;
    }


    printf("Before scatter, data in process %d : %d\n", rank, data);

    MPI_Scatter(buf, 1, MPI_INT, &data, 1, MPI_INT, 0, MPI_COMM_WORLD);


    printf("After scatter, data in process %d : %d\n", rank, data);



    MPI_Finalize();
    return 0;
}

