#include "vector.h"
#include <iostream>
using std::cout;

int main() {
    List<Complex> l;
    l.push_back(Complex(1,2));
    l.push_back(Complex(3,-1));
    Vector v(l);
    l.push_front(Complex(-4,1));
    Vector v1(l);
    Vector v2(v+v1);
//    v2.print();

    cout << scal_prod(v, v1);

    return 0;
}
