#include <iostream>
#include <queue>
#include <utility>
#include <climits>
using namespace std;
int arr[1001][1001];
bool visited[1001][1001];
bool isvalid(int i,int j,int n,int m){
    if(i < 0 or i>=n){
        return false;
    }
    if(j < 0 or j>=m){
        return false;
    }
    return true;
}
int bfs(int i,int j,int k,int l,bool visited[][1001]){
    queue<pair<pair<int,int>,int>> abc;
    abc.push({{i,j},0});
    while(abc.size() > 0){
        auto temp = abc.front().first;
        auto temp2 = abc.front().second;
        i = temp.first;
        j = temp.second;
        visited[i][j] = true;
        if(arr[i][j] == 1){
            return temp2;
        }
        if(isvalid(i+1,j,k,l) && visited[i+1][j] == false){
            abc.push({{i+1,j},temp2+1});
        }
        if(isvalid(i-1,j,k,l) && visited[i-1][j] == false){
            abc.push({{i-1,j},temp2+1});
        }
        if(isvalid(i,j+1,k,l) && visited[i][j+1] == false){
            abc.push({{i,j+1},temp2+1});
        }
        if(isvalid(i,j-1,k,l) && visited[i][j-1] == false){
            abc.push({{i,j-1},temp2+1});
        }
        abc.pop();
    }
    return INT_MAX;
}

void allfalse(bool arr[][1001],int n,int m){
    for(int i=0;i<n;i++){
        fill(arr[i],arr[i]+m,false);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int test;
    cin >> test;
    while(test--){
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> arr[i][j];
            }
        }
        allfalse(visited,n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                allfalse(visited,n,m);
                cout << bfs(i,j,n,m,visited) << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}