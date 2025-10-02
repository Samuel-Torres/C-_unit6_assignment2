#include <iostream>
using namespace std;

void bubbleSortArray(int[], int);
void displayArray(int[], int);

const int SIZE = 8;

int main()
{
	int values[SIZE] = {23, 0, 45, -3, -78, 1, -1, 9};

	cout << "The values before the bubble sort is performed are:" << endl;
	displayArray(values, SIZE);

	bubbleSortArray(values, SIZE);

	cout << "The values after the bubble sort is performed are:" << endl;
	displayArray(values, SIZE);

	return 0;
}

void displayArray(int array[], int elems)
{
	for (int count = 0; count < elems; count++)
		cout << array[count] << "	" << endl;
	cout << endl;
}

void bubbleSortArray(int array[], int elems)
{
	bool swap;
	int temp;
	int bottom = elems - 1;
	do
	{
		swap = false;
		for (int count = 0; count < bottom; count++)
		{
			if (array[count] < array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;

				swap = true;
			}
			displayArray(array, elems);
		}
		bottom--;
	} while (swap != false);
}
