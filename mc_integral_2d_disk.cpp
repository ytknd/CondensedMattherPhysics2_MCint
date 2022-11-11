#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#define ATTEMPTS 1000000
#define INTEGRAL_INTERVAL_MIN 0.0
#define INTEGRAL_INTERVAL_MAX 1.0

int main () {
    double sampled_plots, integrate_surface, radius =1.0;
    std::vector<double> x(ATTEMPTS), y(ATTEMPTS);

    std::random_device seed_gen;
    std::mt19937 engine (seed_gen());
    std::uniform_real_distribution<> rand (INTEGRAL_INTERVAL_MIN, INTEGRAL_INTERVAL_MAX);

    for (long int i = 0; i < ATTEMPTS; i++) {

        x.at(i) = rand (engine);
        y.at(i) = rand (engine);

        if ((x.at(i) * x.at(i) + y.at(i) * y.at(i)) < radius) {
            sampled_plots += 1.0;
        }
    }

    integrate_surface = sampled_plots / ATTEMPTS * 4.0;

    std::cout << integrate_surface << std::endl;
}