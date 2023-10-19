#include <iostream>

using namespace std;

void innerProduct(float* x, float* y, float* out, int* dim)  {
    // We pass in dim because sizeof(x) / sizeof(x[0]) doesn't work here..
    // x is construed as the pointer pointing to x[0] in function scope
    int N = *dim;

    for (int i = 0; i < N; i++) {
        cout << *out << endl;
        *out += x[i] * y[i]; 
    }
}

int main() {
    int dim = 3;
    float a [dim] = { 1.7, 2.2, 3.3 };
    float b [dim] = { 1.0, 1.0, 1.0 };
    float c = 0;

    innerProduct(a, b, &c, &dim);

    cout << c << endl;
    
    return 0;
}
