#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> a;
set<int> b;
bool pb = false;
void dfs(int s,vector<int> edge[],bool visited[],bool first){
    if(first == true){
        a.insert(s);
    }else{
        b.insert(s);
    }
    visited[s] = true;
    for(int x : edge[s]){
        if(visited[x] == false){
            dfs(x,edge,visited,!first);
        }else{
            if(first){
                if(a.find(x) != a.end()){
                    pb = true;
                }
            }else{
                if(b.find(x) != b.end()){
                    pb = true;
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,e;
        cin >> n >> e;
        vector<int> edge[n];
        for(int i=0;i<e;i++){
            int a,b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        a.clear();
        b.clear();
        bool visited[n] = {false};
        dfs(0,edge,visited,true);

        if(pb){
            cout << "No" << '\n';
        }else{
            cout << "Yes" << '\n';
        }
    }
    return 0;
}