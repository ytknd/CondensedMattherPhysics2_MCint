#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#define ATTEMPTS 100
#define INTERVAL_MIN 0.0
#define INTERVAL_MAX 1.0

int main () {
    double sampled_plots, integrate_volume, radius =1.0;
    std::vector<double> x(ATTEMPTS), y(ATTEMPTS), z(ATTEMPTS);

    std::random_device seed_gen;
    std::mt19937 engine (seed_gen());
    std::uniform_real_distribution<> rand (INTERVAL_MIN, INTERVAL_MAX);

    for (long int i = 0; i < ATTEMPTS; i++) {

        x.at(i) = rand (engine);
        y.at(i) = rand (engine);
        z.at(i) = rand (engine);

        if ((x.at(i) * x.at(i) + y.at(i) * y.at(i) + z.at(i) * z.at(i)) < radius) {
            sampled_plots += 1.0;
        }
    }

    integrate_volume = sampled_plots / ATTEMPTS * 8.0;

    std::cout << integrate_volume << std::endl;

    std::ofstream ofs ("result_3d_sphere.txt");
    if (!ofs) {
        std::cerr <<"Fail to file open!" <<std::endl;
        std::exit(1);
    }

    for (long int i = 0; i < ATTEMPTS; i++) {
        ofs << x.at(i) << "\t" << y.at(i) << "\t" << z.at(i) << std::endl;
    }

}