#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MT.h"

int main (void) {

    int sampling_number = 100000000;
    double x, y, z, n, V, r = 1.0;

    init_genrand((unsigned)time(NULL));

    for (int i = 0; i < sampling_number; i++) {

        x = genrand_real1();
        y = genrand_real1();
        z = genrand_real1();

        if ((x * x + y * y + z * z) < r) {

            n += 1.0;
        }
    }

    V = n / sampling_number * 8.0;

    printf("%f\n", V);

    return 0;
}