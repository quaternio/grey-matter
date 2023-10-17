#include <iostream>

using namespace std;

void innerProduct(float* x, float* y, float* out) {
   int N = sizeof(x) / sizeof(x[0]);
   int ySize = sizeof(y) / sizeof(y[0]);
   int outSize = sizeof(out) / sizeof(out[0]);

   if (ySize == N && outSize == N) {
       for (int i = 0; i < N; i++) {
          *out += x[i] * y[i]; 
       }
   }
}

//float* matmul(float* A, float* x) {
//   int N = sizeof(A);
//   float outVec [N];
//
//   if (N > 0) {
//       int D = sizeof(A[0]);
//
//       // TODO 
//   }
//
//   return &outVec;
//}

int main() {
    float a [3] = { 1.7, 2.2 };
    float b [3] = { 1.0, 1.0 };
    float c = 0;

    innerProduct(a, b, &c);

    cout << c << endl;
    
    return 0;
}
