#include "Map.h"
using std::cout;

int main() {
    Map m(3);
    m.insert(1, "hi");
    cout << m.find(1)->m_val;

    return 0;
}
