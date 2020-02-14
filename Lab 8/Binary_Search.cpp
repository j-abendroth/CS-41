/*
 John Abendroth
 Lab 8 Binary Search
 CS 41
 */

 int binarysearch(int arr[], int value, int left, int right)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (arr[mid] == value)
        return mid;
    else if (arr[mid] > value)
        return binarysearch(arr, value, left, mid-1);
    else
        return binarysearch(arr, value, mid+1, right);
}
