/*
 John Abendroth
 Graph List Lab
*/

#include <iostream>
using namespace std;
struct Data{
    int weight, pos;
    char label;
};
struct Node{
    struct Data data;
    struct Node *next;
    Node()
    {
        next = NULL;
    }
};

class MatrixGraph{
public:
    int points;
    struct Node **adj;
    void AddEdge(int x, int y, int z);
    void PrintEdges();
    MatrixGraph(int pts){
        points = pts;
        adj = new Node* [pts];
        for (int i = 0; i < pts; i++)
        {
            adj[i] = new Node;
        }
    };
};

void MatrixGraph::AddEdge(int i, int j, int Weight){
    adj[i]->next = adj[j];
    adj[i]->data.weight = Weight;
}

void MatrixGraph::PrintEdges(){
    cout << "Your edges are: " << endl;

    struct Node *temp;

    for (int i = 0; i < points; i++)
    {
        if (adj[i]->next != NULL)
        {
            temp = adj[i]->next;

            cout << adj[i]->data.label << adj[temp->data.pos]->data.label << " Weight: " << adj[i]->data.weight << endl;
        }
    }
}
int main(){
    int num_points, test = 0, x, y, weight;
    char a,b, new_label;

    cout << "Enter number of points: " << endl;
    cin >> num_points;

    MatrixGraph MG(num_points);

    for (int i = 0; i < num_points; i++)
    {
        cout << "Enter label for vertex " << i+1 << endl;
        cin >> new_label;
        MG.adj[i]->data.label = new_label;
        MG.adj[i]->data.pos = i;
    }

    while (test != -1)
    {
        cout << "Define an edge by listing a pair of vertices" << endl;
        cin >>a>>b;
        cout << "Define this edge's weight: " << endl;
        cin >> weight;

        for (int i = 0; i < num_points; i++)
        {
            if (MG.adj[i]->data.label == a)
                x = i;
            if (MG.adj[i]->data.label == b)
                y = i;
        }
        MG.AddEdge(x, y, weight);

        cout << "Enter -1 to stop or anything else to continue adding edges";
        cin >> test;
    }

    MG.PrintEdges();
}
