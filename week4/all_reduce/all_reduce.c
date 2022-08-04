//
// Created by MD. Zahed on 04/08/2022.
//

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
    printf("Before reduced data: %d in process: %d\n", reduced_data, rank);
    MPI_Allreduce(&data, &reduced_data, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
    printf("After reduced data: %d in process: %d\n", reduced_data, rank);

    MPI_Finalize();
    return 0;
}






