#include<bits/stdc++.h>
using namespace std;
 
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
    int V, E;
    vector<Edge> edges;

public:
    Graph(int v, int e) : V(v), E(e) {}

    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    void bellmanFord(int src) {
        vector<int> dist(V, numeric_limits<int>::max());
        dist[src] = 0;

         for (int i = 0; i < V - 1; ++i) {
            for (const auto& edge : edges) {
                int u = edge.src;
                int v = edge.dest;
                int weight = edge.weight;
                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

         for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle\n";
                return;
            }
        }

         cout << "Vertex   Distance from Source\n";
        for (int i = 0; i < V; ++i) {
            cout << i << "\t\t" << dist[i] << "\n";
        }
    }
};

int main() {
    int V, E;
    cin >> V;  
    Graph graph(V, V * (V - 1));  
    
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                graph.addEdge(i, j, weight);
            }
        }
    }

    int src;
    cin >> src;  

    graph.bellmanFord(src);

    return 0;
}





// int main(){
//     vector<vector<int>> graph = {
//         {0,4,1,0,0},
//         {0,0,0,0,4},
//         {0,2,0,4,0},
//         {0,0,0,0,4},
//         {0,0,0,0,0}
//     };
//     int ak_house = 0;
//     dijkstra(graph,ak_house);

//     return 0;
// }