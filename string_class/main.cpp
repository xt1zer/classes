#include "String.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    String a("hi");
    String b(" fella");
    a.print();

    a.append(b);
    a.print();

    a.append(" whatcha doin?");
    a.append("!");
    a.print();

    a.substr(3, 5).print();

    String* stuff = a.split(' ');

    for(int i(0); i < 4; ++i)
        stuff[i].print();

//    delete[] stuff;

    a.replace("fella", "man");
    a.print();

    return 0;
}
