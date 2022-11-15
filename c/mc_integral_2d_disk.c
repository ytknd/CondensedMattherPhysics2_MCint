#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MT.h"

int main (void) {

    long int sampling_number = 1000000;
    double x, y, n, S, r = 1.0;

    init_genrand((unsigned)time(NULL));

    for (long int i = 0; i < sampling_number; i++) {

        x = genrand_real1();
        y = genrand_real1();

        if ((x * x + y * y) < r) {

            n += 1.0;
        }
    }

    S = n / sampling_number * 4.0;

    printf("%f\n", S);

    return 0;
}