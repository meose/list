#include <iostream>
#include "CustomList.h"
int main() {
	CustomList mylist;
	std::cout << mylist.Len() << "\n";
	mylist.Output();
	mylist.Insert(5, 0);
	mylist.Output();
	mylist.Delete(0);
	mylist.Output();
	mylist.Delete(0);
	mylist.Output();
	mylist.Delete(0);
	mylist.Output();
	mylist.Delete(0);
	mylist.Output();

	mylist.Free();
	mylist.Output();

	mylist.Free();
	mylist.Output();
	mylist.Append(1);
	system("pause");
	return 0;
}