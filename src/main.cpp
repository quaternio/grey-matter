#include <iostream>
#include "Matrix.h"
#include "Linalg.h"

int main() {
  /************************************************/
  // innerProduct test
  /************************************************/
  size_t dim = 3;
  float a [3] = { 1.7, 2.2, 3.3 };
  float b [3] = { 1.0, 1.0, 1.0 };
  float c = 0;

  innerProduct(a, b, &c, dim);

  if (c-0.001 < 7.2 && c+0.001 > 7.2) {
    std::cout << "innerProduct passes" << std::endl;
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
    std::cout << "matMul passes" << std::endl;
  } else {
    std::cout << "matMul failed" << std::endl;
    std::cout << "Expected: " << std::endl;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        std::cout << target[i][j] << ", ";
      }
    }
    std::cout << "" << std::endl;
    std::cout << "Computed: " << std::endl;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        std::cout << *(C->get(i,j)) << ", ";
      }
    }
    std::cout << "" << std::endl;
  }

  delete A;
  delete B;
  delete C;
  
  return 0;
}
