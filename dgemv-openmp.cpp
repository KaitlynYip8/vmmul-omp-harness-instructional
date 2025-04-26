#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

const char* dgemv_desc = "OpenMP dgemv.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */

void my_dgemv(int n, double* A, double* x, double* y) {

   #pragma omp parallel
   {
      int nthreads = omp_get_num_threads();
      int thread_id = omp_get_thread_num();
      // printf("my_dgemv(): Hello world: thread %d of %d checking in. \n", thread_id, nthreads);
      // printf("my_dgemv(): For actual timing runs, please comment out these printf() and omp_get_*() statements. \n");
   }

   // insert your dgemv code here. you may need to create additional parallel regions,
   // and you will want to comment out the above parallel code block that prints out
   // nthreads and thread_id so as to not taint your timings
   int index = 0;
   int* P = new int[n];
  // int value = 0;
  #pragma omp parallel for
   for(int i = 0; i < n * n; i++) {
      index = i / n;
      int j = i % n;
      P[index] += (A[i] * x[j]);
      //    y[(i + 1)/n] = y[(i + 1)/n] + A[(i + 1)] * x[(i + 1) % n];
      //    y[(i + 2)/n] = y[(i + 2)/n] + A[(i + 2)] * x[(i + 2) % n];
      //    y[(i + 3)/n] = y[(i + 3)/n] + A[(i + 3)] * x[(i + 3) % n];
      //    y[(i + 4)/n] = y[(i + 4)/n] + A[(i + 4)] * x[(i + 4) % n];
   }
   #pragma omp parallel for
   for(int i = 0; i < n; i++) {
      y[i] += P[i];
   }
   delete[] P;
}

