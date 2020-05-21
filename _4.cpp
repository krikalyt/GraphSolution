#include <bits/stdc++.h>
using namespace std;
int ans[100000];
int ans2[100000];
int bfs(int i,vector<int> edge[],bool visited[]){
    queue<pair<int,int>> abc;
    abc.push({i,0});
    while(abc.size() > 0){
        auto temp = abc.front();
        visited[temp.first] = true;
        if(ans[temp.first] == 1){
            return temp.second;
        }
        for(int x : edge[temp.first]){
            if(visited[x] == false){
                abc.push({x,temp.second+1});
            }
        }
        abc.pop();
    }
    return INT_MAX;
}

bool isvalid(int i,int j,int n,int m){
    if(i < 0 or i>=n){
        return false;
    }
    if(j < 0 or j>=m){
        return false;
    }
    return true;
}
int main()
{
    freopen("input.txt","r",stdin);
    int test;
    cin >> test;
    while(test--){
        int n,m;
        cin >> n >> m;
        int arr[n][m];
        int index[n][m];
        int z = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> arr[i][j];
                index[i][j] = z;
                ans[z] = arr[i][j];
                ans2[z] = INT_MAX;
                z++;
            }
        }
        int k = n;
        int l = m;
        n = n*m;

        vector<int> edge[n];
        for(int i=0;i<k;i++){
            for(int j=0;j<l;j++){
                
                if(isvalid(i+1,j,k,l)){
                    edge[index[i][j]].push_back(index[i+1][j]);
                }
                if(isvalid(i-1,j,k,l)){
                    edge[index[i][j]].push_back(index[i-1][j]);
                }

                if(isvalid(i,j+1,k,l)){
                    edge[index[i][j]].push_back(index[i][j+1]);
                }
                if(isvalid(i,j-1,k,l)){
                    edge[index[i][j]].push_back(index[i][j-1]);
                }
            }
        }

        bool visited[n]  = {false};
        for(int i=0;i<n;i++){
            fill(visited,visited+n,false);
            ans2[i] = bfs(i,edge,visited);
        }

        for(int i=0;i<n;i++){
            cout << ans2[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}