//
// Created by MD. Zahed on 29/03/2022.
//

#include "mpi.h"
#include <stdio.h>

#define INTERVALS 10000000


int main (int argc, char *argv[]){

    int rank;



    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);






    MPI_Finalize();
    return 0;
}
