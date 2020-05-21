#include <bits/stdc++.h>
using namespace std;
bool dfs(int s,int par,vector<int> edge[],bool visited[]){
    visited[s] = true;
    bool parent = false;
    for(int x : edge[s]){

        if(visited[x] == true && x != par){
            return true;
        }

        if(visited[x] == true && x == s){
            return true;
        }
        if(visited[x] == false){
            bool temp = dfs(x,s,edge,visited);
            if(temp == true){
                parent = true;
            }
        }
    }
    if(parent == true){
        return true;
    }else{
        return false;
    }
}

bool bfs(int i,vector<int> edge[],bool visited[]){
    queue<pair<int,int>> abc;
    abc.push({i,-1});
    while(abc.size() > 0){
        auto temp = abc.front();
        visited[temp.first] = true;
        for(int x : edge[temp.first]){
            if(visited[x] == true && x!=temp.second){
                return true;
            }

            if(x == temp.first){
                return true;
            }
            if(visited[x] == false){
                abc.push({x,temp.first});
            }
        }
        abc.pop();
    }
    return false;
}
bool detectcycle(int n,vector<int> edge[],bool visited[]){
    for(int i=0;i<n;i++){
        if(visited[i] == false && dfs(i,-1,edge,visited)){
            return true;
        }
    }
    return false;
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
        cout << (detectcycle(n,edge,visited)==1?"Yes":"No") << '\n';
    }
    return 0;
}