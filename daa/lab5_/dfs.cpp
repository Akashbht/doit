#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    

public:
    int numVertices;
    vector<vector<int>> adjMatrix;
    Graph(int n) : numVertices(n) {
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
 
    }

    bool DFS(int source, int destination) {
        vector<bool> visited(numVertices, false);
        stack<int> stack;

         
        stack.push(source);
        visited[source] = true;
 
        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();

       
            if (currentVertex == destination)
                return true;

        
            for (int i = 0; i < numVertices; ++i) {
                if (adjMatrix[currentVertex][i] && !visited[i]) {
                    stack.push(i);
                    visited[i] = true;
                }
            }
        }
        return false;
    }
};

int main() {
    int numVertices, source, destination;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;

    Graph g(numVertices);

   
    cout << "Enter the adjacency matrix for the graph:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cin >> g.adjMatrix[i][j];
        }
    }

    cout << "Enter the source and destination vertices: ";
    cin >> source >> destination;

    if (g.DFS(source, destination))
        cout << "Yes, Path Exists" << endl;
    else
        cout << "No Such Path Exists" << endl;

    return 0;
}
