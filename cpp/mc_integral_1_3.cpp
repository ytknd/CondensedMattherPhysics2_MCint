#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#define INTERVAL_MIN 0.0
#define INTERVAL_MAX 1.0

int main () {
    int attempts = 1000000;
    double x, y, z, sampled_plots, integrate_volume, radius = 1.0;
    std::vector<double> x_plot, y_plot, z_plot;
    FILE *gp;

    std::random_device seed_gen;
    std::mt19937 engine (seed_gen());
    std::uniform_real_distribution<> rand (INTERVAL_MIN, INTERVAL_MAX);

    for (long int i = 0; i < attempts; i++) {

        x = rand (engine);
        y = rand (engine);
        z = rand (engine);

        if ((x + y + z) < radius) {
            sampled_plots += 1.0;
            x_plot.push_back(x);
            y_plot.push_back(y);
            z_plot.push_back(z);
        }
    }

    integrate_volume = sampled_plots / attempts;

    std::cout << integrate_volume << std::endl;

    gp = popen("gnuplot", "w");
    fprintf(gp, "set terminal png\n");
    fprintf(gp, "set terminal png size %d,%d\n", 600, 600);
    fprintf(gp, "set output \"mc_integral_1_3.png\"\n");
    fprintf(gp, "set xrange[%f:%f]\n", INTERVAL_MIN, INTERVAL_MAX);
    fprintf(gp, "set yrange[%f:%f]\n", INTERVAL_MIN, INTERVAL_MAX);
    fprintf(gp, "set zrange[%f:%f]\n", INTERVAL_MIN, INTERVAL_MAX);
    fprintf(gp, "set xlabel \"X\"\n");
    fprintf(gp, "set ylabel \"Y\"\n");
    fprintf(gp, "set zlabel \"Z\"\n");

    fprintf(gp, "splot 1-x-y lc rgb \"red\", '-' with points pt 0 lc rgb \"orange\"\n");
    for (int i = 0; i < x_plot.size(); i++) {
        fprintf(gp, "%f\t%f\t%f\n", x_plot.at(i), y_plot.at(i), z_plot.at(i));
    }
    fprintf(gp, "e\n");

    fflush(gp);
    pclose(gp);

}