#include "Matrix.h"

#ifndef SRC_LINALG_H
#define SRC_LINALG_H

void innerProduct(float* x, float* y, float* out, size_t dim);
void matMul(Matrix* A, Matrix* B, Matrix* out);

#endif

