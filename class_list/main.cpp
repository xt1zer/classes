#include <iostream>
#include "linked_list.h"
using namespace std;

int main() {
	List<int> list;
	list.pushBack(4);
	list.pushBack(1);
	list.pushBack(-2);
	list.pushBack(5);
	list.pushFront(7);

	cout << list.popBack() << endl;
	cout << list.popFront() << endl;

	list.reverse();
	list.reverse();

	cout << "List --> ";
	list.print();
	cout << "\n\nList size = " << list.size() << endl;

	system("pause");
	return 0;
}
