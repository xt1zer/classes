#include "complex.h"
#include <iostream>
using std::cout;

int main() {
    Complex c(-1,2);
    Complex c1(-1,-2);
    c -= -2;
    cout << c;

    return 0;
}
