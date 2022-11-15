#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "MT.h"

double Integrand (double variable_integration) {
    return exp (- variable_integration * variable_integration);
}

int main (void) {
    int i, attempts = 100000;
    double x, y, S, count_into_range, ratio_into_range;
    init_genrand ((unsigned) time (NULL));

    for (i = 0; i < attempts; i++) {
        x = genrand_real1 ();
        y = genrand_real1 ();

        if (y < Integrand (x)) {
            count_into_range++;
        }
    }

    S = count_into_range / attempts * 2.0;

    ratio_into_range = count_into_range / attempts * 100;

    printf ("integration result : %f\ntrials in the integration range : %f %%\n", S, ratio_into_range);

    return 0;
}