//
// Created by MD. Zahed on 29/03/2022.
//

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]){

    int rank;
    int csize, localX;
    //int arr[4];
    int *buf = NULL;



    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &csize);


    localX = rank * 3;
    if (rank == 0) {
        buf =(int*) malloc(sizeof(int)*4);
    }

    MPI_Gather(&localX, 1, MPI_INT, buf, 1, MPI_INT, 0, MPI_COMM_WORLD);





    if (rank == 0) {
        for (int i = 0; i < 4; ++i) {
            printf(" %d", buf[i]);
        }
        printf("\n");
    }




    MPI_Finalize();
    return 0;
}
