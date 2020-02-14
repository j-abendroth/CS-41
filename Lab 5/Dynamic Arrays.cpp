/*
John Abendroth
Lab 5 Dynamic Arrays
CS 41
*/

#include <iostream>
using namespace std;

int main() {

	int size, count = 0, input = 0;
	int* arr = NULL;

	cout << "Enter size of the array: " << endl;
	cin >> size;
	arr = new int[size];

	while (input != -1)
	{
		cout << "Enter a number to be input into the array. Enter -1 to exit " << endl;
		cin >> input;

		if (input == -1)
			break;

		if (count >= size)
		{
			int newSize = ++size;
			int* tempArr = new int[newSize];

			for (int i = 0; i < size; i++)
			{
				tempArr[i] = arr[i];
			}

			delete[] arr;
			arr = tempArr;
			size = newSize;
		}

		arr[count] = input;
		count++;
	}

	for (int j = 0; j < size; j++)
	{
		cout << arr[j] << endl;
	}

	return 0;
}
