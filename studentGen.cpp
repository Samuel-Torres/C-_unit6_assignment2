#include <iostream>
using namespace std;

const int MAX_SIZE = 50;

void bubbleSort(int[], int);
int binarySearch(int[], int, int);
double computeMean(int[], int);
void displayArray(int[], int);

int main()
{
    int size;
    int numbers[MAX_SIZE];
    int searchValue;
    int foundIndex;

    cout << "Enter the number of elements (max 50): ";
    cin >> size;

    if (size < 1 || size > MAX_SIZE)
    {
        cout << "Invalid size. Program exiting." << endl;
        return 1;
    }

    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }

    cout << "\nArray as entered: ";
    displayArray(numbers, size);

    bubbleSort(numbers, size);

    cout << "Sorted array: ";
    displayArray(numbers, size);

    cout << "\nEnter an integer to search for: ";
    cin >> searchValue;

    foundIndex = binarySearch(numbers, size, searchValue);

    if (foundIndex != -1)
        cout << "The integer " << searchValue << " was found at position "
             << foundIndex + 1 << " in the sorted array." << endl;
    else
        cout << "The integer " << searchValue << " was not found in the array." << endl;

    double mean = computeMean(numbers, size);
    cout << "The mean of the data set is: " << mean << endl;

    return 0;
}

void bubbleSort(int array[], int elems)
{
    bool swapped;
    int temp;
    for (int pass = 0; pass < elems - 1; pass++)
    {
        swapped = false;
        for (int i = 0; i < elems - 1 - pass; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int binarySearch(int array[], int size, int value)
{
    int first = 0;
    int last = size - 1;
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

double computeMean(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += array[i];
    return static_cast<double>(sum) / size;
}

void displayArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
