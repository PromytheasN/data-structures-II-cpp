#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Graph.h"
using namespace std;

vector<vector<bool>> GenerateFriendshipMatrix(int n){
    vector<vector<bool>> mat(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){ 
                continue;
            }
            mat[i][j] = mat[j][i] = rand()%2;
        }
    }
    return mat;
}

int main(){
    srand(time(0));

    vector<vector<bool>> mat = GenerateFriendshipMatrix(5);

    Graph g(mat);

    // test all features of the Graph class

    g.ShowVertices(); // Test ShoeVertices
    cout << endl;
    g.ShowAdjacencyList(); // Test ShowAdjacencyList
    cout << endl;
    g.ShowEdgeList(); // Test ShowEdgeList
    cout << endl;

    cout << "Total vertices: " << g.VertexCount() << endl; // Test VertexCount
    cout << endl;
    cout << "Total edges: " << g.EdgeCount() << endl; // Test EdgeCount
    cout << endl;

    // Test ShowNeighbors
    int v = 1;
    g.ShowNeighbors(v); 
    cout << endl;


    // Test ShowDegrees
    cout << "The degree of vertex is: " << v << g.Degree(v) << endl; 
    g.ShowDegrees();
    cout << endl;

    // Test HasEdge
    int v1 = 1, v2 = 2;
    cout << "Is there an edge between the vertices " << v1 << " , " << v2 << "? "
    << (g.HasEdge(v1, v2) ? "Yes" : "No") << endl;
    // Test ShowPath 
    vector<int> path = g.Path(0, 3);
    g.ShowPath(0, 3, path);

    //Test HasCycle
    cout << "Does the graph has a cycle? " << (g.HasCycle() ? "Yes" : "No") << endl;

    return 0;
}
