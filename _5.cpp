#include <iostream>
#include <vector>
using namespace std;
int bomb[100001];
int dfs(int s,vector<int> edge[],int power,bool visited[]){
    visited[s] = true;
    if(bomb[s]  == 1){
        power = power - 1;
    }
    if(power < 0){
        return 0;
    }
    int ans = 0;
    int howmany = 0;
    for(int x : edge[s]){
        if(visited[x] == false){
            ans = ans + dfs(x,edge,power,visited);
            howmany++;
        }
    }
    
    if(howmany == 0){
        return 1;
    }else{
        return ans;
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int n,l;
    cin >> n >> l;
    for(int i=0;i<n;i++){
        cin >> bomb[i];
    }
    vector<int> edge[n];
    for(int i=0;i<n-1;i++){
        int from,to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }


    bool visited[n] = {false};
    cout << dfs(0,edge,l,visited);
    cout  << '\n';
    return 0;
}