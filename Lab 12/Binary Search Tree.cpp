/*
 John Abendroth
 CS 41
 Binary Search Tree Lab
*/

#include <iostream>
using namespace std;

class Node{
public:
    int Data;
    Node *left;
    Node *right;
    Node * Add(Node* node, int x);
    void Print(Node* node);
};

Node * Node::Add(Node *node, int data){
    if (node == NULL)
    {
        node = new Node;
        node->Data = data;
        node->left = NULL;
        node->right = NULL;
    }

    if(data < node->Data)
    {
        node->left = Add(node->left, data);
    }
    else if(data > node->Data)
    {
        node->right = Add(node->right, data);
    }

    return node;
}

void Node::Print(Node * node){
    if(node != NULL)
    {
        Print(node->left);
        cout << node->Data << endl;
        Print(node->right);
    }
}

int main(){
    class Node n;
    Node *root = NULL;
    root = n.Add(root, 27);
    n.Add(root, 33);
    n.Add(root, 15);
    n.Add(root, 67);
    n.Add(root, 25);
    n.Add(root, 47);
    n.Add(root, 86);

    n.Print(root);

    return 0;
}
