#include <iostream>
#include "CustomList.h"
int main() {
	CustomList mylist;
	std::cout << mylist.Len() << "\n";
	mylist.Output();
	system("pause");
	return 0;
}