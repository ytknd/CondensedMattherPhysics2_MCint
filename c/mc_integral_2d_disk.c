#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {

    long int sampling_number = 1000000;
    double x, y, n, S, r = 1.0;

    srand((unsigned int)time(NULL));

    for (long int i = 0; i < sampling_number; i++) {

        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if ((x * x + y * y) < r) {

            n += 1.0;
        }
    }

    S = n / sampling_number * 4.0;

    printf("%f\n", S);

    return 0;
}