/*
 Simple Array Lab
 John Abendroth
 CS 41
*/

#include <iostream>
using namespace std;

int main(){

    int x[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter an integer: ";
        cin >> x[i];
    }

    for (int j = 0; j < 5; j ++)
        cout << x[j] << "\n";

    return 0;
}
