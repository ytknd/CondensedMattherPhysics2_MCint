#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#define INTERVAL_MIN 0.0
#define INTERVAL_MAX 1.0

int main () {
    int attempts = 1000000;
    double x, y, z, sampled_plots, integrate_surface;
    std::vector<double> x_plot, y_plot;

    std::random_device seed_gen;
    std::mt19937 engine (seed_gen());
    std::uniform_real_distribution<> rand (INTERVAL_MIN, INTERVAL_MAX);

    for (int i = 0; i < attempts; i++) {

        x = rand (engine);
        y = rand (engine);
        z = rand (engine);

        if (y < (x * x) && y > (x * x * x) && (y * y) > z) {
            sampled_plots += 1.0;
            x_plot.push_back(x);
            y_plot.push_back(y);
        }
    }

    integrate_surface = sampled_plots / static_cast<double>(attempts);

    std::cout << integrate_surface << std::endl;

    std::ofstream ofs ("mc_integral_1_2.txt");
    if (!ofs) {
        std::cerr << "Fail to file open!" << std::endl;
        std::exit(1);
    }

    for (int i = 0; i < x_plot.size(); i++) {
        ofs << x_plot.at(i) << "\t" << y_plot.at(i) << std::endl;
    }
}

