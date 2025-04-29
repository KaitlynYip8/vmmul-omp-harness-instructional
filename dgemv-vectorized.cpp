const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of vectorized vector-matrix multiply
   for(int i = 0; i < n; i++) {
      int index = i * n;
      double sum = 0;
     // y[i] = 0;
      for(int j = 0; j < n; j += 4) {
         sum += (A[index + j] * x[j]);
         sum += (A[index + j + 1] * x[j + 1]);
         sum += (A[index + j + 2] * x[j + 2]);
         sum += (A[index + j + 3] * x[j + 3]);
      }
      y[i] += sum;
   }
}
