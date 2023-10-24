#include <iostream>

using namespace std;

class Matrix {

public:
  size_t inSize;
  size_t outSize;
  float* data;

  float* get(int row, int col) {
    return &(data[row * outSize + col]);
  }

  void row(int rowNum, float* out) {
    for (int i = 0; i < outSize; i++) {
      out[i] = data[outSize * rowNum + i];
    }
  }

  void col(int colNum, float* out) {
    for (int i = 0; i < inSize; i++) {
      out[i] = data[outSize * i + colNum];
    }
  }

  // void T() {
  //   // Transpose the matrix
  //   size_t holder = inSize;
  //   inSize = outSize;
  //   outSize = holder;

  //   // Initialize and populate new data array

  //   // assign new data array to data class member

  //   // destroy old data array
  // }

  // TODO: slice, eigen, cholesky, rank, is_psd, etc..
};

void innerProduct(float* x, float* y, float* out, size_t dim)  {
  // We pass in dim because sizeof(x) / sizeof(x[0]) doesn't work here..
  // x is construed as the pointer pointing to x[0] in function scope
  for (int i = 0; i < dim; i++) {
    cout << "row element i " << x[i] << endl;
    cout << "col element i " << y[i] << endl;
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
      cout << "row " << i << endl;
      cout << "col " << j << endl;
      innerProduct(row, col, out->get(i,j), innerDim);
    }
  }
} 

int main() {
  /************************************************/
  // innerProduct test
  /************************************************/
  size_t dim = 3;
  float a [3] = { 1.7, 2.2, 3.3 };
  float b [3] = { 1.0, 1.0, 1.0 };
  float c = 0;

  innerProduct(a, b, &c, dim);

  if (c == 7.2) {
    cout << "innerProduct passes" << endl;
  } 

  /************************************************/
  // matMul test
  /************************************************/
  Matrix* A = new Matrix();
  Matrix* B = new Matrix();
  Matrix* C = new Matrix();

  A->inSize = 2;
  A->outSize = 3;
  float dataA[6] = {2, 1, 4, 3, 2, 0.5};
  A->data = dataA;

  B->inSize = 3;
  B->outSize = 2;
  float dataB[6] = {1, 0.5, 2, 1, 3, 1};
  B->data = dataB;

  float dataC[4] = {0, 0, 0, 0};
  C->data = dataC;

  matMul(A, B, C);
  float target[2][2] = { {16, 6}, {8.5, 4} };
  bool passed = true;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (*(C->get(i,j)) != target[i][j]) {
        passed = false;
      } 
    }
  }

  if (passed) {
    cout << "matMul passes" << endl;
  } else {
    cout << "matMul failed" << endl;
    cout << "Expected: " << endl;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        cout << target[i][j] << ", ";
      }
    }
    cout << "" << endl;
    cout << "Computed: " << endl;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        cout << *(C->get(i,j)) << ", ";
      }
    }
    cout << "" << endl;
  }

  delete A;
  delete B;
  delete C;
  
  return 0;
}
