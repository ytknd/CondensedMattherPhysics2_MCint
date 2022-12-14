#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#define INTERVAL_MIN 0.0
#define INTERVAL_MAX 1.0

int main () {
    int attempts = 1000000;
    double x, y, z, sampled_plots, integrate_volume, radius =1.0;
    std::vector<double> x_plot, y_plot, z_plot;

    std::random_device seed_gen;
    std::mt19937 engine (seed_gen());
    std::uniform_real_distribution<> rand (INTERVAL_MIN, INTERVAL_MAX);

    for (long int i = 0; i < attempts; i++) {

        x = rand (engine);
        y = rand (engine);
        z = rand (engine);

        if ((x * x + y * y + z * z) < radius) {
            sampled_plots += 1.0;
            x_plot.push_back(x);
            y_plot.push_back(y);
            z_plot.push_back(z);
        }
    }

    integrate_volume = sampled_plots / attempts * 8.0;

    std::cout << integrate_volume << std::endl;

    std::ofstream ofs ("mc_integral_3d_sphere.txt");
    if (!ofs) {
        std::cerr <<"Fail to file open!" <<std::endl;
        std::exit(1);
    }

    for (long int i = 0; i < x_plot.size(); i++) {
        ofs << x_plot.at(i) << "\t" << y_plot.at(i) << "\t" << z_plot.at(i) << std::endl;
    }

}