const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of vectorized vector-matrix multiply

    // Loop over each row of matrix A
   for(int i = 0; i < n; i++) {
      // Calculate starting index of row i in 1D array A
      int index = i * n;
      // Store the dot product of A[i] row and vector x
      double sum = 0;
     // y[i] = 0;

      // Compute dot product of row i of A and vector x
      for(int j = 0; j < n; j++) {
         sum += (A[index + j] * x[j]);
      }
      // Add result to the corresponding element in y
      y[i] += sum;
   }
}
