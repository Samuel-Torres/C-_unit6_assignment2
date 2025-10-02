// SAMUEL TORRES

#include <iostream>
using namespace std;

int searchList(int[], int, int);

const int SIZE = 8;
const int SENTINEL = -999;

int main()
{
	int nums[SIZE] = {3, 6, -19, 5, 5, 0, -2, 99};
	int found;
	int value;
	do
	{
		cout << "Enter an integer to search for (or " << SENTINEL << " to quit):" << endl;
		cin >> value;
		if (value == SENTINEL)
			break;
		found = searchList(nums, SIZE, value);
		if (found == -1)
			cout << "The number " << value
				 << " was not found in the list" << endl;
		else
			cout << "The number " << value << " is in the " << found + 1
				 << " position of the list" << endl;
	} while (true);
	cout << "Program ended." << endl;
	return 0;
}
int searchList(int List[], int numElems, int value)
{
	for (int count = 0; count < numElems; count++)
	{
		if (List[count] == value)
			return count;
	}
	return -1;
}
