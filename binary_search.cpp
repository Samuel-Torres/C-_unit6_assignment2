#include <iostream>
using namespace std;

int binarySearch(int[], int, int);
const int SIZE = 16;

int main()
{
	int found, value;
	int array[] = {0, 2, 2, 3, 5, 9, 11, 12, 12, 12, 13, 17, 18, 19, 19, 34};

	cout << "Enter an integer to search for:" << endl;
	cin >> value;

	found = binarySearch(array, SIZE, value);

	if (found == -1)
		cout << "The value " << value << " is not in the list" << endl;
	else
		cout << "The value " << value << " is in position number "
			 << found + 1 << " of the list" << endl;

	return 0;
}

int binarySearch(int array[], int numElems, int value)
{
	int first = 0;
	int last = numElems - 1;
	int middle;

	while (first <= last)
	{
		middle = first + (last - first) / 2;

		if (array[middle] == value)
			return middle;
		else if (array[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}

	return -1;
}
