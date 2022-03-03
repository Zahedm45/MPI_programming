//
// Created by MD. Zahed on 03/03/2022.
//


#include <time.h>
#include <printf.h>

int main(int argc, char* argv[]) {

    time_t start_time = clock();
    int amount_of_time = 999999999;

    long b = 0;

    for (int i = 0; i < 10; ++i) {
        for (int i = 0; i < amount_of_time; ++i) {
            b++;
        }
    }


    double time_used = (double )(clock() - start_time) / (double) CLOCKS_PER_SEC;

    printf("Time took: %f seconds\n", time_used);
    printf("%ld \n", b);

}
