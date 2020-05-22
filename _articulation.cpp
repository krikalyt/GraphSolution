#include <iostream>
#include <vector>
#include <set>
using namespace std;
int id;
vector<int> ids;
vector<int> lowlink;
void dfs(int s,int par,vector<int> edge[],bool visited[]){
    visited[s] = true;
    ids[s] = lowlink[s] = id;
    id++;
    for(int x : edge[s]){
        if(!visited[x]){
            dfs(x,s,edge,visited);
            lowlink[s] = min(lowlink[s],lowlink[x]);
        }else{
            if(x != par){
                lowlink[s] = min(ids[x],lowlink[s]);
            }
        }
    }
}
set<int> ans;
void dfs2(int s,vector<int> edge[],bool visited[]){
    visited[s] = true;
    for(int x : edge[s]){
        if(!visited[x]){
            dfs2(x,edge,visited);
            if(ids[s] <= lowlink[x] && s!= 0){
                ans.insert(s);
            }
        }
    }
}
bool rootartdfs(int s,vector<int> edge[],bool visited[]){
    visited[s] = true;
    int i = 0;
    for(int x : edge[s]){
        if(!visited[x]){
            rootartdfs(x,edge,visited);
            i++;
        }
    }

    if(i > 1){
        return true;
    }else{
        return false;
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while(t--){
        int n,e;
        cin >> n >> e;
        vector<int> edge[n];
        for(int i=0;i<e;i++){
            int a,b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        bool visited[n] = {false};
        ids.clear();
        lowlink.clear();
        ids.resize(n);
        lowlink.resize(n);

        dfs(0,-1,edge,visited);
        fill(visited,visited+n,false);
        dfs2(0,edge,visited);
        fill(visited, visited+n,false);
        if(rootartdfs(0,edge,visited)){
            ans.insert(0);
        }
        if(ans.size() == 0){
            cout << "No Articulation Point" << '\n';
        }else{
            for(int x : ans){
                cout << x << ' ';
            }
            cout << '\n';
        }
        
    }
    return 0;
}
/*
1 - do DFS traversal and calculate all low link value for every vertex
2 - again do dfs traversal if any edge from u->v where u != 0
    if(id[u] <= lowlink[v]) then u is articulation point where id is discoveredid
3 - for root node use dfs if in dfs tree there are two or more child of root then 
    root node is considered in articulation point
*/