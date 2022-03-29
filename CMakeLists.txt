include_directories(/usr/include/mpi/)
cmake_minimum_required(VERSION 3.17)
project(test C)

set(CMAKE_C_STANDARD 99)

# Add MPI Package to Project
find_package(MPI REQUIRED)

add_executable(test main.c week4/collective_comm/collective_communication.c week4/serial_program/serial.c week4/broad_cast/Broad_cast.c week4/mpi_scatter/scatter.c week4/mpi_gather/gather.c week4/mpi_reduce/reduce.c)


# Add libraries for code completion and compiling
target_link_libraries(test PUBLIC MPI::MPI_C)

