#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double Integrand (double variable_integration) {
    return exp (- variable_integration * variable_integration);
}

int main (void) {
    int i, attempts = 100000;
    double x, y, S, count_into_range, ratio_into_range;
    srand((unsigned int) time (NULL));

    for (i = 0; i < attempts; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if (y < Integrand (x)) {
            count_into_range++;
        }
    }

    S = count_into_range / attempts * 2.0;

    ratio_into_range = count_into_range / attempts * 100;

    printf ("integration result : %f\ntrials in the integration range : %f %%\n", S, ratio_into_range);

    return 0;
}