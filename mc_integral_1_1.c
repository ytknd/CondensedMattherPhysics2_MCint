#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MT.h"

int main (void) {

    int sampling_number = 1000000;
    double x, y, z, n, S, r = 1.0;

    init_genrand((unsigned)time(NULL));

    for (int i = 0; i < sampling_number; i++) {

        x = genrand_real1();
        y = genrand_real1();
        z = genrand_real1();

        if (y < (x * x) && y > (x * x * x) && y > z) {

            n += 1.0;
        }
    }

    S = n / sampling_number;

    printf("%f\n", S);

    return 0;
}