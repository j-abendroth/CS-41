/*
 John Abendroth
 Lab Graph Matrix
*/

#include <iostream>
using namespace std;

class MatrixGraph{
public:
    int points;
    int **adj;
    char *vrt;
    void AddEdge(int x, int y);
    void PrintEdges();
    MatrixGraph(int pts){
        points = pts;
        adj = new int* [pts];
        for (int i = 0; i < pts; i++)
        {
            adj[i] = new int [pts];
            for (int j = 0; j < pts; j++)
            {
                adj[i][j] = 0;
            }
        }
        vrt = new char [pts];
    };
};

void MatrixGraph::AddEdge(int i, int j ){
    adj[i][j] = adj[j][i] = 1;
}

void MatrixGraph::PrintEdges(){
    cout << "Your edges are: " << endl;
    for (int i =0; i < points; i++)
    {
        for (int j = i; j < points; j++)
        {
            if (adj[i][j]==1)
                cout << vrt[i]<<vrt[j]<<endl;
        }
    }
}
int main(){
    int num_points, test = 0, x, y;
    char a,b;

    cout << "Enter number of points: " << endl;
    cin >> num_points;

    MatrixGraph MG(num_points);

    for (int i = 0; i < num_points; i++)
    {
        cout << "Enter label for vertex " << i+1 << endl;
        cin >> MG.vrt[i];
    }

    while (test != -1)
    {
        cout << "Define an edge by listing a pair of vertices" << endl;
        cin >>a>>b;

        for (int i = 0; i < num_points; i++)
        {
            if (MG.vrt[i] == a)
                x = i;
            if (MG.vrt[i] == b)
                y = i;
        }
        MG.AddEdge(x, y);

        cout << "Enter -1 to stop or anything else to continue adding edges";
        cin >> test;
    }

    MG.PrintEdges();
}
