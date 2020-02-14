/*
 John Abendroth
 Lab 6 Array Based Stack
 CS 41
 */

#include <iostream>
using namespace std;

class Stack{
public:
    static const int MaxSize = 10;
    Stack() { count = 0;};
    void Push(int x);
    int Pop();
    bool IsEmpty();

private:
    int count;
    int stk_arr[MaxSize];

};

bool Stack::IsEmpty(){
    return (count == 0);
}

void Stack::Push(int num){

    if(count == MaxSize)
        throw invalid_argument("Stack is full");
    else
    {
        stk_arr[count] = num;
        count++;
    }
}


int Stack::Pop(){
    if(IsEmpty())
        throw invalid_argument("Stack is empty");
    else
    {
        count--;
        return stk_arr[count];
    }
}
