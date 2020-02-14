/*
 Linear Search Lab
 John Abendroth
 CS 41
*/

#include <iostream>
using namespace std;

int search(int arr[], float search_num, int size_arr){

    for (int i = 0; i < size_arr; i++)
    {
        if (search_num == arr[i])
            return i + 1;
    }
    return -1;
}
