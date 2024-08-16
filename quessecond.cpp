#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main() {
    // Load data from the "data.csv" file into an Armadillo mat
    mat data;
    data.load("data.csv", csv_ascii);

    // Get the columns of the mat into two vectors
    vec x = data.col(0);
    vec y = data.col(1);

    // Call polyfit to generate polynomial fits of degree 2, 5, and 8
    vec coefficients_degree2 = polyfit(x, y, 2);
    vec coefficients_degree5 = polyfit(x, y, 5);
    vec coefficients_degree8 = polyfit(x, y, 8);

    // Generate values of x between -3 and 3
    vec x_values = linspace<vec>(-3, 3, 100);

    // Evaluate the three polynomials at the generated x values
    vec y_degree2 = polyval(coefficients_degree2, x_values);
    vec y_degree5 = polyval(coefficients_degree5, x_values);
    vec y_degree8 = polyval(coefficients_degree8, x_values);

    // Store x and the three evaluated values as columns of a matrix
    mat result_matrix(x_values.n_elem, 4);
    result_matrix.col(0) = x_values;
    result_matrix.col(1) = y_degree2;
    result_matrix.col(2) = y_degree5;
    result_matrix.col(3) = y_degree8;
    result_matrix.save("prob2.csv", csv_ascii);
    // Print the result matrix
    

    return 0;
}
