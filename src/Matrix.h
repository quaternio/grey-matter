#ifndef SRC_MATRIX_H
#define SRC_MATRIX_H

class Matrix {

public:
  size_t inSize;
  size_t outSize;
  float* data;

  // TODO: Define constructor

  float* get(int row, int col);
  void row(int rowNum, float* out);
  void col(int colNum, float* out);
  
  // TODO: slice, eigen, cholesky, rank, is_psd, etc..
};

#endif
