#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>


const double alpha = 0.3;   
const double s = 0.2;       
const double delta = 0.05;  
const double A = 1.0;       
const double L = 1.0;       

const int T = 100;
const double dt = 0.1;  

double production_function(double K) {
    return pow(K, alpha) * pow(A * L, 1 - alpha);
}

int main() {
    double K = 1.0;  
    std::vector<double> K_values, Y_values, time_values;

    for (int t = 0; t < T; ++t) {
        double Y = production_function(K);
        double dK = (s * Y - delta * K) * dt;
        K += dK;

        K_values.push_back(K);
        Y_values.push_back(Y);
        time_values.push_back(t * dt);
    }

    std::ofstream file("solow_growth.csv");
    file << "Time,Capital,Output\n";
    for (size_t i = 0; i < K_values.size(); ++i) {
        file << time_values[i] << "," << K_values[i] << "," << Y_values[i] << "\n";
    }
    file.close();

    std::cout << "Simulation complete! Data saved to solow_growth.csv" << std::endl;
    return 0;
}
