/*
 John Abendroth
 Lab 7 Array sort
 CS 41
*/

#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high -1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);

    return (i+1);
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int index = partition(arr, low, high);

        quicksort(arr, low, index - 1);
        quicksort(arr, index + 1, high);
    }
}

int main(){
    int array[] = {27, 10, 86, 15, 47, 25};
    int size = sizeof(array)/sizeof(array[0]);

    quicksort(array, 0, size-1);

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}
