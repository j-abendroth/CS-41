/*
 John Abendroth
 Link Based Queue Lab
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    Node(int new_num){data = new_num; next = NULL;};
};

class Queue{
public:
    void En_queue(int x);
    int De_queue();
    bool IsEmpty();
    int count;
    struct Node *front;
    struct Node *rear;
    Queue(){count = 0; front = NULL; rear = NULL;};
};

bool Queue::IsEmpty(){
    return (count == 0);
}

void Queue::En_queue(int input){
    struct Node *temp = new Node(input);

    if (rear == NULL)
        front = rear = temp;

    rear->next = temp;
    rear = temp;
    count++;
}

int Queue::De_queue(){
    if(IsEmpty())
    {
        cout << "Error: Queue is empty!" << endl;
        return NULL;
    }

    struct Node *temp = front;
    front = front->next;

    if(front == NULL)
        rear = NULL;

    count--;
    return temp->data;
}

int main(){
    Queue q;

    int temp = q.De_queue();
    q.En_queue(10);
    q.En_queue(25);

    cout << "Items in Queue: " << q.count << endl;

    temp = q.De_queue();

    cout << "De-queue'd: " << temp << endl;
    cout << "Items in Queue: " << q.count << endl;
}
