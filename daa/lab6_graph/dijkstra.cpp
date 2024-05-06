#include<bits/stdc++.h>
using namespace std;
 
const int MAX_NODES = 100;
int dijkstra(vector<vector<int>>&graph, int start){
    int n = graph.size();
    vector <bool> visited(n,false);
    vector<int>distance(n,INT_MAX);

    distance[start] = 0;

    for(int count = 0; count < n-1;count++){
        int mindist = INT_MAX;
        int miniindex = -1;
        for(int i = 0; i < n; i++){
            if(!visited[i] && distance[i]<mindist){
                mindist = distance[i];
                miniindex = i;

            }

        }
        visited[miniindex] = true;
        for(int i =0; i< n;i++){
            if(!visited[i] && graph[miniindex][i] && distance[miniindex]!= INT_MAX && distance[miniindex]+graph[miniindex][i]<distance[i]){
                distance[i] = distance[miniindex]+graph[miniindex][i];

            }

        }

    }
    for(int i = 0;i < n;i++){
        cout<<i+1<<":";
        if(distance[i]==INT_MAX){
            cout<<"infinity"<<endl;

        }
        else{
            cout<<distance[i]<<endl;
        }
    }
}
int main(){
    vector<vector<int>> graph = {
        {0,4,1,0,0},
        {0,0,0,0,4},
        {0,2,0,4,0},
        {0,0,0,0,4},
        {0,0,0,0,0}
    };
    int ak_house = 0;
    dijkstra(graph,ak_house);

    return 0;
}