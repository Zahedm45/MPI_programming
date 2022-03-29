//
// Created by MD. Zahed on 29/03/2022.
//


#include <mpi.h>
#include <printf.h>

int main(int argc, char *argv[]) {
    int taskid;

    int tag = 11111;

    MPI_Status status;
    MPI_Request request;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &taskid);

    /* determine partner and then send/receive with partner */
    if (taskid == 0) {
        int send_data = 10;
        MPI_Isend(&send_data, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &request);

    } else if (taskid == 1) {
        int received_data = 0;

        printf("Before: From process: %d, data: %d\n", taskid, received_data);

        MPI_Irecv(&received_data, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, &status);

        printf("Before: From process: %d, data: %d\n", taskid, received_data);

    }



    MPI_Finalize();
    return 0;
}

