/*
 *
 * Linear algebra utilites
 *
 * Author: Thomas Noel
 * Date: 10/20/23
 */

void innerProduct(float* x, float* y, float* out, int* dim)  {
  // We pass in dim because sizeof(x) / sizeof(x[0]) doesn't work here..
  // x is construed as the pointer pointing to x[0] in function scope
  int N = *dim;

  for (int i = 0; i < N; i++) {
    *out += x[i] * y[i]; 
  }
}



