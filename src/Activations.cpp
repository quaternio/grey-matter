#include "Activations.h"

ReLU::ReLU(size_t size) {
  _size = size; 

  // Initialize the gradient data
  float io_grad [_size];
  for (int i=0; i<_size; i++) {
    float row [_size];
    io_grad[i] = row; 
    for (int j=0; j<_size; j++) {
      io_grad[i][j] = 0.;
    }
  }

  _io_grad = io_grad;
}

void ReLU::apply(float* input, float* output) {
  for (int i=0; i<_size; i++) {
    if (input[i] > 0) {
      output[i] = input[i];
    } else {
      output[i] = 0.;
    }
  }

  // TODO: Populate _io_grad
}
