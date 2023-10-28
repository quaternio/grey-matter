/*
 *
 * Linear algebra utilites
 *
 * Author: Thomas Noel
 * Date: 10/20/23
 */

#include "Linalg.h"

void innerProduct(float* x, float* y, float* out, size_t dim)  {
  // We pass in dim because sizeof(x) / sizeof(x[0]) doesn't work here..
  // x is construed as the pointer pointing to x[0] in function scope
  for (int i = 0; i < dim; i++) {
    *out += x[i] * y[i]; 
  }
}

void matMul(Matrix* A, Matrix* B, Matrix* out) {
  if (A->outSize != B->inSize) {
    throw "Invalid dimensions! Could not compute matrix product.";
  }

  size_t inDim = A->inSize;
  size_t outDim = B->outSize;
  size_t innerDim = A->outSize;
  out->inSize = inDim;
  out->outSize = outDim;
  float row[A->outSize];
  float col[B->inSize];

  // Simple O(N^3) solution
  for (int i = 0; i < inDim; i++) {
    A->row(i, row);
    for (int j = 0; j < outDim; j++) {
      B->col(j, col);
      innerProduct(row, col, out->get(i,j), innerDim);
    }
  }
} 

