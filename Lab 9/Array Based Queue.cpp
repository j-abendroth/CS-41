/*
 John Abendroth
 Lab 9 Array based queue
 CS 41
*/

#include <iostream>
using namespace std;

class Queue{
public:
    Queue(){count = 0; front = 0; back = -1;};
    void En_queue(int x);
    int De_queue();

private:
    static const int MaxSize = 10;
    int count, front, back;
    int queue_arr[MaxSize];
    bool IsEmpty();

};

bool Queue::IsEmpty(){
    return (count == 0);
}

void Queue::En_queue(int input){
    if (count == MaxSize)
    {
        throw invalid_argument("Queue is full!");
    }
    else
    {
        back++;
        queue_arr[back] = input;
        count++;
    }
}

int Queue::De_queue(){
    int num = 0;
    if (IsEmpty())
    {
        throw invalid_argument("Queue is empty!");
    }
    else
    {
        num = queue_arr[front];
        front++;
        count--;
    }
    return num;
}
