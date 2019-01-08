#include "Map.h"
using std::cout;

int main() {
    Map m(3);
    m.insert(4, "hi");
    cout << m.get(4);

    return 0;
}
