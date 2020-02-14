/*
 John Abendroth
 CS 41
 Lab Link Based Stack
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

class List{
public:
    List(){top = NULL; count = 0;};
    void Push(int x);
    int Pop();
    bool IsEmpty();
private:
    struct Node* top;
    int count;
};

bool List::IsEmpty(){
    return (count == 0);
}

void List::Push(int num){
    struct Node *node;
    node = (struct Node*)malloc(sizeof(struct Node));

    node->data = num;
    node->next = top;
    top = node;

    count++;
}

int List::Pop(){
    if(IsEmpty())
    {
        cout << "Stack is empty" << endl;
        return NULL;
    }
    else
    {
        cout << "Popped element is " << top->data << endl;
        int temp = top->data;
        top = top->next;
        count--;
        return temp;
    }
}
