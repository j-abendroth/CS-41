/*
John Abendroth
Program 2
CS 41
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	string name;
	int weight;
	Node *nextByName; //next node sorted by names
	Node *nextByWeight; //next node sorted by weight
	Node();
	Node(const string &new_name, int new_weight) { name = new_name; weight = new_weight; nextByName = NULL; nextByWeight = NULL; };
};

class List {
public:
	void insert(const string &name, int weight); //insert new values into list
	void printByName(); //print list ascending order by name
	void printByWeight(); //print list ascending order by weight
	List() { nameHead = NULL; weightHead = NULL; };
private:
	Node * nameHead;
	Node *weightHead;
};


void List::insert(const string &name, int weight) {
	Node *insert_node = new Node(name, weight);

	Node **pnew_person;
	Node *new_person;

	//Insert new name sorted by iterating through list until new name is greater than next name
	for (pnew_person = &nameHead; (new_person = *pnew_person); pnew_person = &(new_person->nextByName))
	{
		if (new_person->name >= name)
		{
			break;
		}
	}

	insert_node->nextByName = new_person;
	*pnew_person = insert_node;

	// insert new weight sorted by iterating through list until new weight is greater than next weight
	for (pnew_person = &weightHead; (new_person = *pnew_person); pnew_person = &(new_person->nextByWeight))
	{
		if (new_person->weight >= weight)
		{
			break;
		}
	}
	insert_node->nextByWeight = new_person;
	*pnew_person = insert_node;
}

void List::printByName() {
	Node *temp = nameHead;

	//print list ascending by names by iterating through until the temp node is NULL
	if (temp == NULL)
		cout << "Empty List" << endl;
	else
	{
		cout << "\n" << "Names & weights sorted (ascending) by name: ";
		while (temp != NULL)
		{
			cout << temp->name << " - ";
			cout << temp->weight << ", ";
			temp = temp->nextByName;
		}
	}
}

void List::printByWeight() {
	Node *temp = weightHead;

	//print list ascending by weights by iterating through until the temp node is NULL
	if (temp == NULL)
		cout << "Empty List" << endl;
	else
	{
		cout << "\n" << "Names & weights sorted (ascending) by weight: ";
		while (temp != NULL)
		{
			cout << temp->name << " - ";
			cout << temp->weight << ", ";
			temp = temp->nextByWeight;
		}
	}
}

int main() {
	List dll;
	int temp_weight;
	string temp_name;


	for (int i = 0; i < 15; i++)
	{
		cout << "Enter name followed by weight on a new line" << endl;
		cin.ignore();
		getline(cin, temp_name);
		cin >> temp_weight;

		dll.insert(temp_name, temp_weight);
	}
	dll.printByName();
	dll.printByWeight();

	system("PAUSE");
	return 0;
}

/*
Enter name followed by weight on a new line
Jim
150
Enter name followed by weight on a new line
Tom
212
Enter name followed by weight on a new line
Michael
174
Enter name followed by weight on a new line
Abe
199
Enter name followed by weight on a new line
Richard
200
Enter name followed by weight on a new line
April
117
Enter name followed by weight on a new line
Claire
124
Enter name followed by weight on a new line
Bobby
109
Enter name followed by weight on a new line
Bob
156
Enter name followed by weight on a new line
Kevin
145
Enter name followed by weight on a new line
Jason
182
Enter name followed by weight on a new line
Brian
150
Enter name followed by weight on a new line
Chris
175
Enter name followed by weight on a new line
Steven
164
Enter name followed by weight on a new line
Annabelle
99

Names & weights sorted (ascending) by name: Abe - 199, Annabelle - 99, April - 117, Bob - 156, Bobby - 109, Brian - 150, Chris - 175, Claire - 124, Jason - 182, Kevin - 145, Michael - 174, Richard - 200, Steven - 164, Tom - 212, im - 150,
Names & weights sorted (ascending) by weight: Annabelle - 99, Bobby - 109, April - 117, Claire - 124, Kevin - 145, Brian - 150, im - 150, Bob - 156, Steven - 164, Michael - 174, Chris - 175, Jason - 182, Abe - 199, Richard - 200, Tom - 212, Press any key to continue . . .
*/