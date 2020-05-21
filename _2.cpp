#include <bits/stdc++.h>
using namespace std;
void dfs(int s,vector<int> edge[],bool visited[]){
    visited[s] = true;
    for(int x : edge[s]){
        if(visited[x] == false){
            dfs(x,edge,visited);
        }
    }
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

        bool visited[n] = {false};
        int component = 0;
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                dfs(i,edge,visited);
                component++;
            }
        }
        cout << component << '\n';
    }
    return 0;
}