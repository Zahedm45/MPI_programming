//
// Created by MD. Zahed on 29/03/2022.
//

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]){

    int rank;
    int rank_size;
    int *buf = NULL;

    int ITER = 15;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &rank_size);
    int root_rank = rank_size -1;


    if (rank == root_rank) {
        buf = (int*) malloc(sizeof(int) * ITER);
        buf[12] = 100;

    }


    int send_data[3] = {rank, 2, rank};
    MPI_Gather(&send_data, 3, MPI_INT, buf, 3, MPI_INT, root_rank, MPI_COMM_WORLD);


    if (rank == root_rank) {

        for (int i = 0; i < ITER; ++i) {
            printf(" %d", buf[i]);
        }
        printf("\n");
    }


    MPI_Finalize();
    return 0;
}

/*
int arr[] = {2,4,6,8,9,4};//6 elements
int Length  = sizeof(arr)/sizeof(int);*/
