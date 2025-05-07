#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Edge{
public:
    // assume u and v are two vertices 
    // vertices are zero-indexed
    int u;
    int v;

    Edge(){
        u = -1; // invalid vertex index
        v = -1; // invalid vertex index
    }

    Edge(int _u, int _v){
        u = _u;
        v = _v;
    }
};

class Graph
{
private:
    vector<int> vertices;
    vector<vector<int>> adjacencyList;
    vector<Edge> edgeList;

public:
    Graph()
    {
    }
    Graph(vector<vector<bool>> adjacencyMatrix){
        // adjacencyMatrix has dimension n x n with zeroes along the main diagonal
        // assume row 0 is for vertex 0, row 1 is for vertex 1 and so on
        // TASKS: add methods to do the following:
        // build vertices, adjacencyList and edgeList from adjacencyMatrix.
        BuildVertices(adjacencyMatrix.size());
        BuildAdjacencyList(adjacencyMatrix);
        BuildEdgeList();
    }
    void BuildVertices(int numberOfVertices){
        for (int i = 0; i < numberOfVertices; i++)
        {
            vertices.push_back(i);
        }
    }
    void BuildAdjacencyList(vector<vector<bool>> adjacencyMatrix){
        // Build adjacency list 
        int num = adjacencyMatrix.size(); // Get vertices
        adjacencyList.resize(num);

        for(int i = 0; i < num; i++){ // Iterate over vertex i
            for(int j = 0; j < num; j++){ // Iterate over edges j
                if(adjacencyMatrix[i][j]){
                    adjacencyList[i].push_back(j); // Add edge to adjacencyList
                }
            }
        }
    }
    void BuildEdgeList(){
        // build edge list from adjacency list
        for(int u = 0; u < adjacencyList.size(); u++){
          for(int v : adjacencyList[u]){
                if (u < v) edgeList.push_back(Edge(u, v)); // If not duplicate
            }
        }               
    }
    void ShowVertices(){
        cout << "Vertices: ";
        for (int i = 0; i < vertices.size(); i++)
        {
            cout << vertices[i] << ", ";
        }
        cout << endl;
    }
    void ShowAdjacencyList(){
        // display adjacency list
        cout << "Adjacency List:" << endl;
        for(int i = 0; i < adjacencyList.size(); i++){ // Iterate through each vertex
            cout << i << ": ";
            for(int neighbor : adjacencyList[i]){ // iterate through neighbors of current vertex
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    void ShowEdgeList(){
        // display edge list
        cout << "Edge List:" << endl;
        for(Edge ed : edgeList){ // Iteratte edge in the edge list
            cout << "(" << ed.u << ", " << ed.v << ")" << endl; // Print the current edge (u, v)
        }        
    }
    int VertexCount(){
        // returns the number of vertices in the graph
        return vertices.size();
    }
    int EdgeCount(){
        // returns the number of edges in the graph
        return edgeList.size();
    }
    void ShowNeighbors(int v){
        // display neighbors of vertex v i.e. all friends of v
        if(v < 0 || v >= adjacencyList.size()){ // If vertex index is valid
            cout << "Out of Range!" << endl; // Cout out of range
            return;
        }
        cout << "Neighbors of vertex v " << v << ": ";       
        for(int neighbor : adjacencyList[v]){ // Iterate through neighbors of vertex v
            cout << neighbor << ", "; // Cout neighbors
        }
        cout << endl;
    }
    int Degree(int v){
        // return the degree of vertex v i.e. number of friends of v
        if(v >= adjacencyList.size() || v < 0) { // If vertex index is not valid
            cout << "Invalid vertex!" << endl;
            return -1;
        }
        return adjacencyList[v].size();        
    }
    void ShowDegrees(){
        // display degrees of all vertices sorted in descending order of degree
        cout << "Degrees of vertices:\n";
        vector<pair<int, int>> degrees;
        for(int i = 0; i < vertices.size(); i++){
            degrees.push_back(make_pair(Degree(i), i)); // Add degrees, vertex num pair
        }
        sort(degrees.rbegin(), degrees.rend()); // Sort degrees in descending order
        for(auto &d : degrees){     // Iterate degrees
            cout << "Vertex: " << d.second << " Degree: " << d.first << endl;
        }
    }
    bool HasEdge(int v1, int v2){
        // returns true if there is an edge between vertices v1 n v2; false otherwise
        if(v1 < 0 || v1 >= adjacencyList.size() || v2 < 0 || v2 >= adjacencyList.size()){ // If out of range
            cout << "Invalid Vertex!" << endl;
            return false;
        }
        // Iterate through the neighbors of v1
        for(int neighbor : adjacencyList[v1]) {
            if (neighbor == v2) { // If v2 found
                return true;
            }
        }
        return false; // Else return false
    }
    void DFS(int v1, int v2, vector<bool> &visited, vector<int> &path){
        // depth first search to find a path from v1 to v2
        visited[v1] = true;
        path.push_back(v1); // Push back current vertex to path
        // Base case
        if(v1 == v2) return;
        for(int neighbor : adjacencyList[v1]) {
            if(!visited[neighbor]){ // If neighbor not viseted
                DFS(neighbor, v2, visited, path);
                if(visited[v2]) return;
            }
        }
        // If v2 is not reached remove last vertex
        path.pop_back();
    }
    vector<int> Path(int v1, int v2){
        // returns the path (all vertices that fall along the path) from vertex v1 to vertex v2
        // if there is no path, return an empty vector
        if(v1 < 0 || v1 >= adjacencyList.size() || v2 < 0 || v2 >= adjacencyList.size() || v1 == v2){
            cout << "Invalid vertex index!\n";
            return vector<int>();
        }
        vector<bool> visited(vertices.size(), false);
        vector<int> path;
        DFS(v1, v2, visited, path);
        if(!visited[v2]){
            path.clear();
        }
        return path;
    }
    void ShowPath(int v1, int v2, vector<int> path){
        if(v1 < 0 || v1 >= adjacencyList.size() || v2 < 0 || v2 >= adjacencyList.size()){
            cout << "Invalid vertex index!\n";
            return;
        }
        if(path.size() == 0){
            cout << "No path from " << v1 << " to " << v2 << endl;
            return;
        }
        cout << "Path from " << v1 << " to " << v2 << ": ";
        for(int i = 0; i < path.size(); i++){
            cout << path[i] << ", ";
        }
        cout << endl;
    }
    bool HasCycle(){
        // return true if graph has a cycle (starting from a node we follow edges to return back to the same vertex); false otherwise
        int num = adjacencyList.size(); // Vertices num
        vector<bool> visited(num, false); // Initialize bool vector to keep truck of viseted vertices
        for(int v = 0; v < num; v++){ // Iterate through vertices
            if(!visited[v]){ // If not viseted
                if(HasCycle(v, visited, -1))
                    return true;
            }
        }
        return false;
    }
    bool HasCycle(int current, vector<bool> &visited, int parent){
        visited[current] = true; // Current was viseted
        // Iterate all neighbors
        for(int neighbor : adjacencyList[current]) {
            if(!visited[neighbor]){ // If neighbor not viseted
                if (HasCycle(neighbor, visited, current)) {
                    return true; // Cycle found
                }
            }
            else if(neighbor != parent){ // If visited but not parent
                return true;// If neighbor visited and not parent
            }
        }
        return false; // If no cycle is found
    }
};
#endif