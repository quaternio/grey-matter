#include "Activations.h"

ReLU::ReLU(size_t size) {
  _size = size; 

  // Initialize the gradient data
  for (int i=0; i<_size; i++) {
    float* row = new float[_size];
    _io_grad[i] = row; 
    for (int j=0; j<_size; j++) {
      row[j] = 0.;
    }
    delete [] row;
  }
}

ReLU::~ReLU() {
  // Free each sub-array
  for (int i = 0; i < _size; i++) { 
    delete [] _io_grad[i];
  }

  // Free the array of pointers
  delete [] _io_grad;
}

void ReLU::apply(float* input, float* output) {
  for (int i=0; i<_size; i++) {
    if (input[i] > 0) {
      output[i] = input[i];
    } else {
      output[i] = 0.;
    }
  }

  // Populate the Jacobian
  for (int i = 0; i < _size; i++) {
    for (int j = 0; j < _size; j++) {
      if (i != j) {
        _io_grad[i][j] = 0;
      } else {
        if (output[i] > 0) {
          _io_grad[i][j] = 1;
        } else {
          _io_grad[i][j] = 0;
        }
      }
    } 
  }
}
