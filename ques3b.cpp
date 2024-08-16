#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main() {
    for (int x = 0; x < 100; x++) {
        // Calculate a value using the loop index
        double value = 1.0 / pow(2, x);

        // Create a 2x2 matrix An with specific values
        mat Ax = {{1, 1}, {1, 1 + value}};

        // Determine the rank of matrix An
        int ran_Ax = arma::rank(Ax,1e-6);

        // Retrieve the machine epsilon
        double machi_epsi = datum::eps;

        // Check if the rank is 1
        if (ran_Ax == 1) {
            cout << "Rank is 1 for n = " << x << "\n";
            cout << "Difference = " << abs(value - machi_epsi) << "\n";
            break;
        }
    }
    return 0;
}
