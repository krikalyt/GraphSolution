#include <bits/stdc++.h>
using namespace std;
int ans[1000][1000];
bool visited[1000][1000];
bool isvalid(int i,int j,int n,int m){
    if(i < 0 || i >= n){
        return false;
    }
    if(j < 0 || j >= m){
        return false;
    }
    return true;
}

void bfs(int k,int l,vector<vector<int> > &matrix){
    
    queue<pair<int,int>> abc;
    for(int i=0;i<k;i++){
        fill(visited[i],visited[i]+l,false);
        for(int j=0;j<l;j++){
            ans[i][j] = INT_MAX;
            if(matrix[i][j] == 2){
                abc.push({i,j});
                visited[i][j] = true;
                ans[i][j] = 0;
            }
        }
    }

    while(abc.size() > 0){
        auto temp = abc.front();
        abc.pop();
        int i = temp.first;
        int j = temp.second;
        if(isvalid(i+1,j,k,l) && visited[i+1][j] == false && matrix[i+1][j] == 1){
            abc.push({i+1,j});
            ans[i+1][j] = ans[i][j] + 1;
            matrix[i+1][j] = 2;
            visited[i+1][j] = true;
        }
        if(isvalid(i-1,j,k,l) && visited[i-1][j] == false && matrix[i-1][j] == 1){
            abc.push({i-1,j});
            ans[i-1][j] = ans[i][j] + 1;
            matrix[i-1][j] = 2;
            visited[i-1][j] = true;

        }
    
        if(isvalid(i,j+1,k,l) && visited[i][j+1] == false && matrix[i][j+1] == 1){
            abc.push({i,j+1});
            ans[i][j+1] = ans[i][j] + 1;
            matrix[i][j+1] = 2;
            visited[i][j+1] = true;

        }
        if(isvalid(i,j-1,k,l) && visited[i][j-1] == false && matrix[i][j-1] == 1){
            abc.push({i,j-1});
            ans[i][j-1] = ans[i][j] + 1;
            matrix[i][j-1] = 2;
            visited[i][j-1] = true;
        }
    }
}

int rotOranges(vector<vector<int> > &matrix, int R, int C)
{
    bfs(R,C,matrix);
    int maxe = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(matrix[i][j] == 1){
                return -1;
            }
            if(matrix[i][j] == 2)
                maxe = max(maxe,ans[i][j]);
        }
    }
    return maxe;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while(t--){
        int r,c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);
        for(int i=0;i<r;i++){
            matrix[i].resize(c);
            for(int j=0;j<c;j++){
                cin >> matrix[i][j];
            }
        }
        cout << rotOranges(matrix,r,c) << '\n';
    }
    return 0;
}