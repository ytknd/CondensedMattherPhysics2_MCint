#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {

    int sampling_number = 1000000;
    double x, y, z, n, S, r = 1.0;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < sampling_number; i++) {

        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        z = (double)rand() / RAND_MAX;

        if (y < (x * x) && y > (x * x * x) && (y * y) > z) {

            n += 1.0;
        }
    }

    S = n / sampling_number;

    printf("%f\n", S);

    return 0;
}