/*
 Lab Loop Lab 4
 John Abendroth
 CS 41
*/
#include <iostream>
using namespace std;

int sum(int n){
    int sums = 0;

    for (int i = 0; i <= n; i++)
        sums += i;

    return sums;
}
