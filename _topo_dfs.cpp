#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalsort(int n,vector<int> edge[],vector<int> zero,int indegree[]){
    vector<int> ans;
    queue<int> abc;
    for(int i=0;i<zero.size();i++){
        abc.push(zero[i]);
    }

    while(abc.size() > 0){
        int temp = abc.front();
        ans.push_back(temp);
        indegree[temp] = -1;
        for(int x : edge[temp]){
            indegree[x] = indegree[x] - 1;
            if(indegree[x] == 0){
                abc.push(x);
            }
        }
        abc.pop();
    }
    return ans;
}

void dfs(int s,vector<int> edge[],list<int>& ans,bool visited[]){
    visited[s] = true;
    for(int x : edge[s]){
        if(visited[x] == false){
            dfs(x,edge,ans,visited);
        }
    }

    ans.push_front(s);
}

int main()
{
    freopen("input.txt","r",stdin);
    //Topological Sort 
    //Directed Graph
    int test;
    cin >> test;
    while(test--){
        int n,e;
        cin  >> e >> n;
        vector<int> edge[n];
        for(int i=0;i<n;i++){
            int from,to;
            cin >> from >> to;
            edge[from].push_back(to);
        }

        bool visited[n] = {false};
        list<int> arr;
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                dfs(i,edge,arr,visited);
            }
        }

        for(int x : arr){
            cout << x  << ' ';
        }
        cout << '\n';
    }

    return 0;
}