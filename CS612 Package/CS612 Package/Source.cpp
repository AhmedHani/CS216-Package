#include <iostream>
#include "Sort.h"

using namespace std;

int main() {
	int* arr = new int[3];
	arr[1] = 3;
	arr[0] = 6;
	arr[2] = 5;

	int length = 3;

	Sort<int> s(arr, length);
	arr = s.insertion_sort();

	for (int i = 0; i < length; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}