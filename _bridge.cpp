#include <bits/stdc++.h>
using namespace std;
int id;
vector<int> ids;
vector<int> lowlink;
vector<pair<int,int>> ans;
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
                lowlink[s] = min(lowlink[x],lowlink[s]);
            }
        }
    }
}

void dfs2(int s,vector<int> edge[],bool visited[]){
    visited[s] = true;
    for(int x : edge[s]){
        if(visited[x] == false){
            dfs2(x,edge,visited);
            if(ids[s] < lowlink[x]){
                int mine = min(s,x);
                int maxe = max(s,x);
                ans.push_back({mine,maxe});
            }
        }
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
        for(int i=0;i<e;i++){
            int a,b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        //pre-requisite
        id = 0;
        ids.clear();
        lowlink.clear();
        ans.clear();
        ids.resize(n);
        lowlink.resize(n);
        bool visited[n] = {false};
        dfs(0,-1,edge,visited);
        fill(visited,visited+n,false);
        dfs2(0,edge,visited);
        if(ans.size() == 0){
            cout << "No Edges" << '\n';
            continue;
        }
        cout << ans.size() << '\n';
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
    return 0;
}