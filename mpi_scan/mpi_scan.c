//
// Created by MD. Zahed on 14/04/2022.
//

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    // Get my rank
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    // Get the sum of all ranks up to mine and print it
    int total;
    MPI_Scan(&my_rank, &total, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    printf("[MPI process %d] Total = %d.\n", my_rank, total);

    MPI_Finalize();

    return EXIT_SUCCESS;
}