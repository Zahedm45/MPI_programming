//
// Created by MD. Zahed on 04/08/2022.
//

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



int main (int argc, char *argv[]){

    int rank;
    int csize, localX;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &csize);

    localX = rank * 3;
    int *buf =(int*) malloc(sizeof(int) * csize);

    MPI_Allgather(&localX, 1, MPI_INT, buf, 1, MPI_INT,  MPI_COMM_WORLD);

    assert(buf != NULL);
    printf("Rank: %d\n", rank);
    for (int i = 0; i < 4; ++i) {
        printf(" %d", buf[i]);
    }
    printf("\n");

    MPI_Finalize();
    return 0;
}
