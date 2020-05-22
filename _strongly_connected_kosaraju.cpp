#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int> abc;
void dfs(int s,vector<int> edge[],bool visited[]){
    visited[s] = true;
    for(int  x : edge[s]){
        if(!visited[x])
            dfs(x,edge,visited);
    }
    abc.push(s);
}

void dfs2(int s,vector<int> edge[],bool visited[]){
    visited[s] = true;
    // cout << s << ' ';
    for(int  x : edge[s]){
        if(!visited[x])
            dfs2(x,edge,visited);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while(t--){
        int n;
        int e;
        cin >> n >> e;
        vector<int> edge[n];
        vector<int> edge2[n];
        for(int i=0;i<e;i++){
            int a,b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge2[b].push_back(a);
        }

        //
        while(abc.size() > 0){
            abc.pop();
        }
        bool visited[n] = {false};
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                dfs(i,edge,visited);
            }
        }
        fill(visited,visited+n,false);
        int ans = 0;
        while(abc.size() > 0){
    
            if(visited[abc.top()] == false){
                dfs2(abc.top(),edge2,visited);
                ans++;
            }
            abc.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
    Algorithm
1 - do dfs and push all the node into stack according to their's finish time
2 - reverse all the edges
3 - again do dfs but starting node will be top value of stack example dfs(top,edge,visited) and print all the node in 
the traversal it would be strongly connected component.
4 - repeat 3
*/