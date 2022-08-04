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


    int amount_of_pro = MPI_Init(&argc, &argv);

    int rank;
    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int per_process = amount_of_time / 3;

    if (rank == 0) {
        int result;
        MPI_Recv(&result, 1, MPI_INT, 1, 000, MPI_COMM_WORLD, &status);
        printf("I am from process 0. The result is: %d \n", result);



        int result2;
        MPI_Recv(&result2, 1, MPI_INT, 2, 000, MPI_COMM_WORLD, &status);
        result += result2;
        printf("I am from process 0. The result is: %d \n", result);



        int result3;
        MPI_Recv(&result3, 1, MPI_INT, 3, 000, MPI_COMM_WORLD, &status);
        result += result3;



        double time_used = (double )(clock() - start_time) / (double) CLOCKS_PER_SEC;

        printf("Time took: %f seconds\n", time_used);
        printf("I am from process 0. The result is: %d \n", result);

    } else if (rank == 1) {
        int sending_value = 0;
        for (int i = 0; i < per_process; ++i) {
            sending_value++;
        }

        MPI_Send(&sending_value, 1, MPI_INT, 0, 000, MPI_COMM_WORLD);


//        MPI_Send(&sending_value, 1, MPI_INT, 0, 000,MPI_COMM_WORLD);

    } else if (rank == 2) {
        int sending_value = 0;

        for (int i = 0; i < per_process; ++i) {
            sending_value++;
        }

        MPI_Send(&sending_value, 1, MPI_INT, 0, 000, MPI_COMM_WORLD);

    } else if (rank == 3) {
        int sending_value = 0;

        for (int i = 0; i < per_process; ++i) {
            sending_value++;
        }

        MPI_Send(&sending_value, 1, MPI_INT, 0, 000, MPI_COMM_WORLD);

    }

    MPI_Finalize();




}










/*
time_t start_time = clock();
int amount_of_time = 1000000000;

int b = 0;
for (int i = 0; i < amount_of_time; ++i) {
b++;
}

double time_used = (double )(clock() - start_time) / (double) CLOCKS_PER_SEC;

printf("Time took: %f seconds\n", time_used);
printf("%d \n", b);*/

