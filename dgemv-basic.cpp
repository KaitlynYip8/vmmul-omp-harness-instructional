#include <cstdio>
const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of basic matrix multiply

   // Go through each row of the matrix A
   for(int i = 0; i < n; i++) {
      // Start at row i in the 1D array A
      int index = i * n;
      // Multiply row i of A with vector x and add to y[i]
      for(int j = 0; j < n; j++) {
         y[i] += (A[index + j] * x[j]);
      }
   }
}
