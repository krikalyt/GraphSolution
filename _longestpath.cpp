#include <iostream>
#include <queue>
int maxe;
using namespace std;
int dfs(int s,vector<int> edge[],bool visited[]){

    cout << s << " ";
    visited[s] = true;
    priority_queue<int> abc;
    int howmuch = 0;
    for(int x : edge[s]){
        if(visited[x] == false){
            int temp = dfs(x,edge,visited) + 1;
            abc.push(temp);
            howmuch++;
        }
    }

    if(howmuch == 0){
        return 0;
    }else{
        int t = abc.top();
        abc.pop();
        int t2 = 0;
        if(abc.size() > 0){
            t2 = abc.top();
            abc.pop();
        }
        maxe = max(maxe,t+t2);
        return t;
    }
}

int main()
{
    int test;
    cin >> test;
    while(test--){
        maxe = 0;
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
        dfs(0,edge,visited);
        cout << maxe << '\n';
    }
    
    return 0;
}