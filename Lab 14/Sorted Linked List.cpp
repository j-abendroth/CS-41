/*
 John Abendroth
 Sorted Linked List Lab
 CS41
*/

#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
	node(int new_num){data = new_num; next = NULL;};
};

class LinkedList{
public:
	node *front;
	void insert(int x);
	void print();
	LinkedList(){front = NULL;};
};

void LinkedList::insert(int number){
	if(front == NULL)
	{
		front = new node(number);
	}
	else
	{
		node *temp = new node(number);

		node *temp2 = front;
		node **temp3 = &front;

		//https://stackoverflow.com/questions/4825030/c-add-to-linked-list-in-sorted-order
		while(temp2 != NULL && temp2->data < temp->data)
		{
			temp3 = &temp2->next;
			temp2 = temp2->next;
		}
		*temp3 = temp;
		temp->next = temp2;
	}
}

void LinkedList::print(){
	node* temp = front;

	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main(){
	LinkedList LL;
	int input = 0;

	cout << "Enter a number to be added to the linked list (-1 to exit) " << endl;

	while(true){
		cin >> input;
		if(input != -1)
			LL.insert(input);
		else
			break;
	}

	LL.print();

	return 0;
}
