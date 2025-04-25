const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of vectorized vector-matrix multiply
   for(int i = 0; i < n * n; i += 5) {
         y[i/n] = y[i/n] + A[i] * x[i % n];
         y[(i + 1)/n] = y[(i + 1)/n] + A[(i + 1)] * x[(i + 1) % n];
         y[(i + 2)/n] = y[(i + 2)/n] + A[(i + 2)] * x[(i + 2) % n];
         y[(i + 3)/n] = y[(i + 3)/n] + A[(i + 3)] * x[(i + 3) % n];
         y[(i + 4)/n] = y[(i + 4)/n] + A[(i + 4)] * x[(i + 4) % n];
      }
}
