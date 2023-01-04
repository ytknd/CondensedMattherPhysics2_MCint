#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {

    int sampling_number = 10000000;
    double x, y, z, w, n, V, r = 1.0;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < sampling_number; i++) {

        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        z = (double)rand() / RAND_MAX;
        w = (double)rand() / RAND_MAX;

        if ((x + y + z) < r && (x * x + y * y + z * z) > w) {

            n += 1.0;
        }
    }

    V = n / sampling_number;

    printf("%f\n", V);

    return 0;
}