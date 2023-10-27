/*
 * A matrix
 *
 * Written by Thomas Noel
 */

#include "Matrix.h"

// TODO: Define a constructor

float* Matrix::get(int row, int col) {
  return &(data[row * outSize + col]);
}

void Matrix::row(int rowNum, float* out) {
  for (int i = 0; i < outSize; i++) {
    out[i] = data[outSize * rowNum + i];
  }
}

void Matrix::col(int colNum, float* out) {
  for (int i = 0; i < inSize; i++) {
    out[i] = data[outSize * i + colNum];
  }
}

// void Matrix::T() {
//   // Transpose the matrix
//   size_t holder = inSize;
//   inSize = outSize;
//   outSize = holder;

//   // Initialize and populate new data array

//   // assign new data array to data class member

//   // destroy old data array
// }
