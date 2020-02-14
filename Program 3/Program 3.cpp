/*
 John Abendroth
 CS 41
 Program 3
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//struct for holding all the input names and weights
struct Data {
	string name;
	int weight;
};

//struct for holding all node pointers
struct Node {
	struct Data data;
	struct Node *left;
	struct Node *right;

	Node(Data passedData)
	{
		data = passedData;
		left = NULL;
		right = NULL;
	}
};


class BinarySearchTree {
public:
	BinarySearchTree() { root = NULL; };
	void buildTree();
	void addData(Data passedData);
	void printPreorder();
	void printInorder();
	void printPostorder();
	int getHeight(Node *node);
	int getNumberOfLeaves(Node *node);
	void search();
	int getLowestWeight();
	string getFirstName();
	struct Node *root;
private:
	void addData(Node *node, Data data);
	void printPreorder(Node *node);
	void printInorder(Node *node);
	void printPostorder(Node *node);
	int getLowestWeight(Node *node, int weight);
	string getFirstName(Node *node);
	int Max(int a, int b) { return ((a > b) ? a : b); };
};

//function to take names and weights and add to the tree
void BinarySearchTree::buildTree() {
	string name;
	int weight;

	for (int i = 0; i < 15; i++)
	{
		cout << "Enter Name: ";
		cin.ignore();
		getline(cin, name);

		cout << "Enter weight: ";
		cin >> weight;

		struct Data newperson;
		newperson.name = name;
		newperson.weight = weight;

		addData(newperson);
	}
}

//function to actualy add to tree
//recursively checks whether new name is greater or less than current nodes and adds appropriately
void BinarySearchTree::addData(Data newdata) {
	if (root == NULL)
		root = new Node(newdata);
	else
		addData(root, newdata);
}

void BinarySearchTree::addData(Node *node, Data newdata) {
	if (node->data.name > newdata.name)
	{
		if (node->left == NULL)
			node->left = new Node(newdata);
		else
			addData(node->left, newdata);
	}
	else if (node->data.name < newdata.name)
	{
		if (node->right == NULL)
			node->right = new Node(newdata);
		else
			addData(node->right, newdata);
	}
	else
		cout << "Error: Duplicate name" << endl;
}

//recursive function to print out a preorder traversal of the tree
void BinarySearchTree::printPreorder() {
	cout << "Preorder traversal:" << endl;

	if (root == NULL)
		cout << "Tree is empty!" << endl;
	else
		printPreorder(root);
}

void BinarySearchTree::printPreorder(Node *node) {
	if (node != NULL)
	{
		cout << node->data.name << " " << node->data.weight << endl;
		printPreorder(node->left);
		printPreorder(node->right);
	}
}

//recursive function to print out an inorder traversal of the tree
void BinarySearchTree::printInorder() {
	cout << "Inorder traversal of tree: " << endl;

	if (root == NULL)
		cout << "Tree is empty!" << endl;
	else
		printInorder(root);
}

void BinarySearchTree::printInorder(Node *node) {
	if (node != NULL)
	{
		printInorder(node->left);
		cout << node->data.name << " " << node->data.weight << endl;
		printInorder(node->right);
	}
}

//recursive function to print out a postorder traversal of the tree
void BinarySearchTree::printPostorder() {
	cout << "Postorder traversal of tree: " << endl;

	if (root == NULL)
		cout << "Tree is empty!" << endl;
	else
		printPostorder(root);
}

void BinarySearchTree::printPostorder(Node *node) {
	if (node != NULL)
	{
		printPostorder(node->left);
		printPostorder(node->right);
		cout << node->data.name << " " << node->data.weight << endl;
	}
}

//recursively finds the height of the tree by traversing through each the left and right sides of the tree and taking the biggest height of the two
int BinarySearchTree::getHeight(Node *node) {
	if (node == NULL)
		return 0;
	else
	{
		int lh = getHeight(node->left);
		int rh = getHeight(node->right);

		return 1 + Max(lh, rh);
	}
}

//recursively traverses the tree until it finds leaves with no children
int BinarySearchTree::getNumberOfLeaves(Node *node) {
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
		return getNumberOfLeaves(node->left) + getNumberOfLeaves(node->right);
}

//recursively searches for a given name by checking if the given name is greater than the current node and traversing appropriately until the name is either found or the next node is NULL
struct Node* BSTSearch(Node *node, string search_name) {
	if (node == NULL)
		return NULL;
	else if (node->data.name == search_name)
		return node;

	if (node->data.name < search_name)
		return BSTSearch(node->right, search_name);
	else
		return BSTSearch(node->left, search_name);
}

void BinarySearchTree::search() {
	string name;

	cout << "Enter name to search: " << endl;
	cin.ignore();
	getline(cin, name);

	struct Node *temp = BSTSearch(root, name);

	if (temp == NULL)
	{
		cout << "No match exists " << endl;
	}
	else
	{
		cout << "Found!" << endl;
		cout << "Name: " << temp->data.name << " Weight: " << temp->data.weight << endl;
	}
}

int BinarySearchTree::getLowestWeight() {
	if (root == NULL)
		return 0;
	else
		return getLowestWeight(root, root->data.weight);
}

//finds the lowest weight in the tree by recursively finding the smallest weights on each the left and right sides, and then taking the smallest of those two
int BinarySearchTree::getLowestWeight(Node *node, int weight) {
	if (node == NULL)
		return weight;
	else
	{
		return min(min(node->data.weight, getLowestWeight(node->left, node->data.weight)), min(node->data.weight, getLowestWeight(node->right, node->data.weight)));
	}
}

//finds the first name alphabetically by simply traversing the left side of the tree until there are no more nodes, since any names alphabetically before the root will always be on the left side
string BinarySearchTree::getFirstName() {
	if (root == NULL)
	{
		cout << "Tree is empty!" << endl;
		return NULL;
	}
	else
		return getFirstName(root);
}

string BinarySearchTree::getFirstName(Node *node) {
	if (node->left == NULL)
		return node->data.name;
	else
		return getFirstName(node->left);
}

int main() {
	BinarySearchTree tree;

	tree.buildTree();

	tree.printPreorder();
	tree.printInorder();
	tree.printPostorder();

	cout << "Height of the tree: " << tree.getHeight(tree.root) << endl;
	cout << "number of leaves in the tree: " << tree.getNumberOfLeaves(tree.root) << endl;

	tree.search();

	cout << "\n" << "Lowest weight in the tree: " << tree.getLowestWeight() << endl;

	cout << "First name by alphabetical order: " << tree.getFirstName() << endl;

	system("PAUSE");
}

/*
Enter Name: Aaron
Enter weight: 225
Enter Name: Kyle
Enter weight: 300
Enter Name: Jeff
Enter weight: 200
Enter Name: Thomas
Enter weight: 170
Enter Name: Tanner
Enter weight: 160
Enter Name: Ryan
Enter weight: 120
Enter Name: Brianna
Enter weight: 120
Enter Name: Kaela
Enter weight: 130
Enter Name: Saige
Enter weight: 110
Enter Name: Nick
Enter weight: 150
Enter Name: Alyssa
Enter weight: 140
Enter Name: Megan
Enter weight: 150
Enter Name: Daniel
Enter weight: 160
Enter Name: Seth
Enter weight: 145
Enter Name: Bre
Enter weight: 115
Preorder traversal:
aron 225
Kyle 300
Jeff 200
Brianna 120
Alyssa 140
Bre 115
Daniel 160
Kaela 130
Thomas 170
Tanner 160
Ryan 120
Nick 150
Megan 150
Saige 110
Seth 145
Inorder traversal of tree:
Alyssa 140
Bre 115
Brianna 120
Daniel 160
Jeff 200
Kaela 130
Kyle 300
Megan 150
Nick 150
Ryan 120
Saige 110
Seth 145
Tanner 160
Thomas 170
aron 225
Postorder traversal of tree:
Bre 115
Alyssa 140
Daniel 160
Brianna 120
Kaela 130
Jeff 200
Megan 150
Nick 150
Seth 145
Saige 110
Ryan 120
Tanner 160
Thomas 170
Kyle 300
aron 225
Height of the tree: 7
number of leaves in the tree: 5
Enter name to search:
Jeff
Found!
Name: Jeff Weight: 200

Lowest weight in the tree: 110
First name by alphabetical order: Alyssa
Press any key to continue . . .
*/