//
// Created by MD. Zahed on 03/03/2022.
//


/* communication.c

   02346, F20, DTU

   For instructions, see databar exercise 3.
*/
#include "mpi.h"
#include <stdio.h>
#include <time.h>

#define  MASTER		0

int main (int argc, char *argv[])
{
    time_t start_time = clock();
    int amount_of_time = 999999999;
    int amount_of_pro;
    int rank;



    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &amount_of_pro);

    int per_process = amount_of_time / (amount_of_pro - 1);

    if (rank == 0) {
        long result;
        MPI_Recv(&result, 1, MPI_LONG, 1, 000, MPI_COMM_WORLD, &status);
        printf("I am from process 0. The result is: %ld \n", result);



        long result2;
        MPI_Recv(&result2, 1, MPI_LONG, 2, 000, MPI_COMM_WORLD, &status);
        result += result2;
        printf("I am from process 0. The result is: %ld \n", result);



        long result3;
        MPI_Recv(&result3, 1, MPI_LONG, 3, 000, MPI_COMM_WORLD, &status);
        result += result3;



        double time_used = (double )(clock() - start_time) / (double) CLOCKS_PER_SEC;

        printf("Time took: %f seconds\n", time_used);
        printf("I am from process 0. The result is: %ld \n", result);
        printf("%d \n", amount_of_pro);

    } else {
        long sending_value = 0;


        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < per_process; ++i) {
                sending_value++;
            }
        }

        MPI_Send(&sending_value, 1, MPI_LONG, 0, 000, MPI_COMM_WORLD);


    }

    MPI_Finalize();




}


