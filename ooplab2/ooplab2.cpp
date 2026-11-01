

#include "ooplab2.h"
#include "cstr.h"
#include "cstrarray.h"
using namespace std;

int main()
{
	CStrArray arr(3);
	arr += new Cstr("Ban");
	arr += new Cstr("Apple");
	arr += new Cstr("Cherry");
	cout << arr.isSorted() << endl;
	cout << arr << endl;
	arr.Sort();
	cout << arr.isSorted() << endl;
	cout << arr << endl;
	arr.Sort();
	arr.SortLen();
	cout << arr << endl;

	for (int i = 0; i < 3; ++i) {
		delete arr[i];
	}

	return 0;
}
