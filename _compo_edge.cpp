#include <bits/stdc++.h>
using namespace std;
int dfs(int s, vector<int> adj[], vector<bool>& visited) 
{ 
    // Adding all the edges connected to the vertex 
    int adjListSize = adj[s].size(); 
    visited[s] = true; 
    for (long int i = 0; i < adj[s].size(); i++) { 
        if (visited[adj[s][i]] == false) { 
            adjListSize += dfs(adj[s][i], adj, visited); 
        } 
    } 
    return adjListSize; 
} 
  
int maxEdges(vector<int> adj[], int nodes) 
{ 
    int res = INT_MIN; 
    vector<bool> visited(nodes, false); 
    for (long int i = 0; i < nodes; i++) { 
        if (visited[i] == false) { 
            int adjListSize = dfs(i, adj, visited, nodes); 
            res = max(res, adjListSize/2); 
        }       
    } 
    return res; 
} 
  
int main()
{
    freopen("input.txt","r",stdin);
    int test;
    cin >> test;
    while(test--){
        int n,e;
        cin >> n >> e;
        vector<int> edge[n];
        for(int i=0;i<e;i++){
            int from,to;
            cin >> from >> to;
            edge[from].push_back(to);
            edge[to].push_back(from);
        }
        cout << maxEdges(edge,n) << '\n';
    }
    return 0;
}