#include <cstddef>

#ifndef SRC_ACTIVATIONS_H
#define SRC_ACTIVATIONS_H

class ReLU {
private:
  size_t _size;
  float** _io_grad;

public:
  ReLU(size_t size);
  ~ReLU();
  void apply(float* input, float* output);
};

#endif
