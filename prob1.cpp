#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int
main(void)
{
   
   arma_rng::set_seed_random() ;
   mat A = randn(4,4);

   A.save("matrix1.csv", csv_ascii);

   mat b = randn(4,1);
   A.print("A: ");
   b.print("b: ");
   vec s = solve(A, b);
   s.print("Solution: ");
  return 0;
}