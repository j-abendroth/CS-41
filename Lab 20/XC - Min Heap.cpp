/*
 John Abendroth
 XC - Min Heap
*/

#include <iostream>
#include <algorithm>
using namespace std;


class Heap{
public:
    int *dataArr;
    int count, size;
    void Add(int data);
    int Delete();
    void resize();
    Heap(){count = 0; size = 1; dataArr = new int [size];};
private:
    int parent(int x){return (x-1)/2;};
    int left(int x){return ((2*x)+1);};
    int right(int x){return ((2*x)+2);};
    void swap (int *x, int *y){int temp = *x; *x = *y; *y = temp;};
    void ReHeap(int x);
    int findMin();
};

void Heap::resize(){
    int newsize = ++size;

    int* tempArr = new int[newsize];

    for (int i = 0; i < size; i++)
        tempArr[i] = dataArr[i];

    delete[] dataArr;
    dataArr = tempArr;
    size = newsize;
}

int Heap::findMin(){
    int min_number = dataArr[0];

    for (int i = 0; i < count; i++)
        min_number = min(min_number, dataArr[i]);

    return min_number;
}

void Heap::Add(int data){
    if (count >= size)
        resize();

    count++;
    int end = count -1;

    dataArr[end] = data;

    while (end != 0 && dataArr[parent(end)] > dataArr[end])
    {
        swap(&dataArr[end], &dataArr[parent(end)]);
        end = parent(end);
    }
}

void Heap::ReHeap(int index){
    int l = left(index);
    int r = right(index);
    int smallest = index;

    if (l < count && dataArr[l] < dataArr[index])
        smallest = l;
    if (r < count && dataArr[r] < dataArr[smallest])
        smallest = r;
    if (smallest != index)
    {
        swap (&dataArr[index], &dataArr[smallest]);
        ReHeap(smallest);
    }
}

int Heap::Delete(){
    if(count == 1)
    {
        count--;
        return dataArr[0];
    }

    int root = dataArr[0];
    dataArr[0] = dataArr[count-1];
    int min_num = findMin();
    dataArr[0] = min_num;
    count --;
    ReHeap(0);

    return root;
}

int main(){
    Heap h;

    h.Add(7);
    h.Add(1);
    h.Add(3);
    h.Add(6);
    h.Add(5);
    h.Add(9);
    h.Add(2);
    h.Add(8);

    for (int i =0; i < h.size; i++)
        cout << h.dataArr[i] << endl;

    int x = h.Delete();
    cout << "deleted: " << x << endl;

    for (int i =0; i < h.size; i++)
        cout << h.dataArr[i] << endl;

    return 0;
}
