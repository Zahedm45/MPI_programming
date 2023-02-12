//
// Created by MD. Zahed on 12/02/2023.
//


#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Step 1: Partitioning
    // Divide the data into equal parts for each process
    int chunk_size = N / world_size;
    int start = world_rank * chunk_size;
    int end = start + chunk_size;

    // Step 2: Communication
    // Each process receives a portion of the data from the other processes
    int* data = (int*)malloc(N * sizeof(int));
    MPI_Scatter(data, chunk_size, MPI_INT, data + start, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Step 3: Aggregation
    // Each process aggregates its portion of the data
    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += data[i];
    }

    // Step 4: Mapping
    // The result is mapped back to the root process
    int total_sum;
    MPI_Reduce(&sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Print the result
    if (world_rank == 0) {
        printf("Total sum: %d\n", total_sum);
    }

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;
}


/*
 * In this example, each process performs a portion of the data, communicates the results
 * to the root process, aggregates its portion of the data, and finally maps the result
 * back to the root process.
 */