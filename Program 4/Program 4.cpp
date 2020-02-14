/*
 John Abendroth
 CS 41
 Program 4
*/

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;
const int TABLE_SIZE = 17;

//Struct for the nodes in the chaining colission resolution
struct HashNode {
	int value, scope;
	string varName;
	struct HashNode* next;
	HashNode() { varName = ""; scope = 0; value = 0; this->next = NULL; };
	HashNode(string varName, int scope, int value)
	{
		this->varName = varName;
		this->scope = scope;
		this->value = value;
		this->next = NULL;
	}
};

//Hash table class
class HashTable {
public:
	int Hash(string x);
	void insert(string varName, int scope, int value);
	void print(string varName, int scope);
	void arithmetic(string varName, int scope, string operation, int value);
	//initialize whole table to NULL
	HashTable()
	{
		table = new HashNode * [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}
private:
	struct HashNode** table;
};

//hashing function, sums ordinal values of the chars and multiplies by position in string
int HashTable::Hash(string x) {
	int hashVal = 0;
	double hashSize = x.size();

	for (int i = 0; i < hashSize; i++)
	{
		hashVal += (int)x[i] * (i + 1);
	}
	return hashVal % TABLE_SIZE;
}

//Insertion into hash table
void HashTable::insert(string varName, int scope, int value) {
	int hash_val = Hash(varName);

	//if hash position in table is NULL, insert
	if (table[hash_val] == NULL)
		table[hash_val] = new HashNode(varName, scope, value);
	//else traverse the chain until the current node is not NULL, then create a new node at the next position in the list
	else
	{
		struct HashNode* temp = table[hash_val];
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new HashNode(varName, scope, value);
	}
}

//Function to handle PRINT command of BORG language
void HashTable::print(string varName, int scope) {
	int hash_val = Hash(varName);
	//create a temp node at the position in the hash table where the variable to be printed is located
	struct HashNode* temp = table[hash_val];

	//traverse the chain until at the end of the list
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;

	//if the temp node is at NULL, the variable to be printed hasn't been inserted into the table
	if (temp == NULL)
		cout << varName << " UNDEFINED" << endl;
	else if (temp->varName == varName && temp->scope <= scope)
		cout << temp->varName << " is " << temp->value << endl;
	else //if the variable hash was found but the scope level didn't match, then print not in scope
		cout << varName << " NOT IN SCOPE" << endl;
}

//function to handle all possible arithmetic supported by BORG
void HashTable::arithmetic(string varName, int scope, string operation, int value = 0) {
	int hash_val = Hash(varName);
	struct HashNode* temp = table[hash_val];

	//traverse chain until end of list, if node is NULL then the variable wasn't inserted into the hash table
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	if (temp == NULL)
		cout << varName << " UNDEFINED " << endl;
	else
	{
		if (temp->varName == varName && temp->scope <= scope)
		{
			if (operation == "++")
				temp->value++;
			else if (operation == "--")
				temp->value--;
			else if (operation == "=")
				temp->value = value;
			else if (operation == "*")
				cout << temp->varName << " " << operation << " " << value << " is " << temp->value * value << endl;
			else if (operation == "+")
				cout << temp->varName << " " << operation << " " << value << " is " << temp->value + value << endl;
			else if (operation == "-")
				cout << temp->varName << " " << operation << " " << value << " is " << temp->value - value << endl;
			else if (operation == "/")
				cout << temp->varName << " " << operation << " " << value << " is " << temp->value / value << endl;
			else if (operation == "%")
				cout << temp->varName << " " << operation << " " << value << " is " << temp->value % value << endl;
			else if (operation == "^")
				cout << temp->varName << " " << operation << " " << value << " is " << pow(double(temp->value), value) << endl;
		}
		else
			cout << varName << " NOT IN SCOPE " << endl;
	}
}

int main() {
	HashTable ht;
	int scope_level = 0, num;
	string input, name, operation, temp, file_location;

	cout << "Enter file location" << endl;
	getline(cin, file_location);

	ifstream inputss(file_location);
	while (!inputss.eof()) //keep reading while not at the end of the file
	{
		//if temp isn't empty set it back to nothing
		if (!temp.empty())
			temp = "";
		else
			inputss >> input; //move the first word  from input stream into the input variable

		//check which BORG command matches the input
		if (input == "COM")
			inputss.ignore(numeric_limits<streamsize>::max(), '\n');
		else if (input == "START")
			scope_level++;
		else if (input == "FINISH")
			scope_level--;
		else if (input == "VAR") //if input matches the VAR command, insert into the hash table
		{
			inputss >> input;
			name = input;
			inputss >> input;
			inputss >> input;
			istringstream ss;
			ss.str(input);
			ss >> num;
			ht.insert(name, scope_level, num);
		}
		else if (input == "PRINT")
		{
			inputss >> input;
			name = input;
			inputss >> input;

			//if input matches an arithmetic operation, input the next words on the line and perform the arithmetic
			if (input == "*" || input == "/" || input == "+" || input == "-" || input == "%" || input == "^")
			{
				operation = input;
				inputss >> input;
				istringstream stringstream;
				stringstream.str(input);
				stringstream >> num;
				ht.arithmetic(name, scope_level, operation, num);
			}
			//else just print the variable
			else
			{
				ht.print(name, scope_level);
				temp = input;
			}
		}
		else //if nothing has matched yet, the input is either an increment operator or an equal sign
		{
			name = input;
			inputss >> input;
			if (input == "++" || input == "--")
				ht.arithmetic(name, scope_level, input);
			else if (input == "=")
			{
				operation = input;
				inputss >> input;
				istringstream ss2;
				ss2.str(input);
				ss2 >> num;
				ht.arithmetic(name, scope_level, operation, num);
			}
			else
				cout << "missed " << input << endl; // check to see if something missed
		}
	}
	system("PAUSE");
	return 0;
}
