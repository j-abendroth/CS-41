/*
 Binary Tree Lab
 John Abendroth
 CS 41
*/

#include <iostream>
using namespace std;


class bTree{
public:
    int count, size;
    void newsize();
    void add(int x);
    void print(int x);
    bTree(){count = 0; size = 1; dataArray = new int [size];};
private:
    int* dataArray = NULL;
};

void bTree::newsize(){
    int newSize = ++size;

    int* tempArr = new int [newSize];

    for (int i = 0; i < size; i++)
        tempArr[i] = dataArray[i];

    delete[] dataArray;
    dataArray = tempArr;
    size = newSize;

}

void bTree::add(int data){
    if (count >= size)
        newsize();

    dataArray[count] = data;
    ++count;
}

void bTree::print (int index){
    if (index < count)
    {
        cout << dataArray[index] << " ";
        print((2*index)+1);
        print((2*index)+2);
    }
}

int main(){
    bTree b;

    b.add(3);
    b.add(5);
    b.add(9);
    b.add(6);
    b.add(8);
    b.add(20);
    b.add(10);

    b.print(0);
}
