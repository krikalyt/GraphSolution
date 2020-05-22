#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <set>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    string a;
    cin >> a;
    int n = a.size();
    if(n == 1){
        cout << 0 << '\n';
        return 0;
    }

    set<int> ans[10];
    for(int i=0;i<n;i++){
        ans[a[i]-'0'].insert(i);
    }

    vector<int> edge[n];
    edge[0].push_back(1);
    for(int x : ans[a[0]-'0']){
        edge[0].push_back(x);
    }
    for(int i=1;i<n-1;i++){
        edge[i].push_back(i+1);
        edge[i].push_back(i-1);
        for(int x : ans[a[i]-'0']){
            if(x <= i)
                continue;
            edge[i].push_back(x);
        }
    }

    queue<pair<int,int>> abc;
    bool visited[n] = {false};
    abc.push({0,0});
    visited[0] = true;
    
    // for(int i=0;i<n-1;i++){
    //     for(int x : edge[i]){
    //         cout << x <<  ' ';
    //     }
    //     cout << '\n';
    // }
    while(abc.size()){
        int temp = abc.front().first;
        int dist = abc.front().second;
        abc.pop();
        if(temp == n-1){
            cout << dist << '\n';
            return 5;
        }
        for(int x : edge[temp]){
            if(visited[x] == false){
                abc.push({x,dist+1});
                visited[x] = true;
            }
        }
    }
    return 0;
}