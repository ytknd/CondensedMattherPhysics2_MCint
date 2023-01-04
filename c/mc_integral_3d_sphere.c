#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {

    int sampling_number = 100000000;
    double x, y, z, n, V, r = 1.0;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < sampling_number; i++) {

        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        z = (double)rand() / RAND_MAX;

        if ((x * x + y * y + z * z) < r) {

            n += 1.0;
        }
    }

    V = n / sampling_number * 8.0;

    printf("%f\n", V);

    return 0;
}