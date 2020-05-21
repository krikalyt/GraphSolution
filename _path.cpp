#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;
int ans[1000][1000];
bool visited[1000][1000];

bool isvalid(int i,int j,int n){
    if(i < 0 || i >= n){
        return false;
    }
    if(j < 0 || j >= n){
        return false;
    }
    return true;
}


void bfs(){
    int n = 1000;
    queue<pair<int,int>> abc;
    queue<int> h;
    abc.push({0,0});
    h.push(0);
    visited[0][0] = true;
    while(abc.size() > 0){
        auto temp  = abc.front();
        int i = temp.first;
        int j = temp.second;
        
        ans[i][j] = h.front();
        if(isvalid(i-2,j+1,n) && (visited[i-2][j+1] == false)){
            abc.push({i-2,j+1});
            h.push(h.front()+1);
            visited[i-2][j+1] = true;
        }

        if(isvalid(i-2,j-1,n) && (visited[i-2][j-1] == false)){
            abc.push({i-2,j-1});
            h.push(h.front()+1);
            visited[i-2][j-1] = true;
        }

        if(isvalid(i+2,j+1,n) && (visited[i+2][j+1] == false)){
            abc.push({i+2,j+1});
            h.push(h.front()+1);
            visited[i+2][j+1] = true;
        }

        if(isvalid(i+2,j-1,n) && (visited[i+2][j-1] == false)){
            abc.push({i+2,j-1});
            h.push(h.front()+1);
            visited[i+2][j-1] = true;
        }

        if(isvalid(i+1,j+2,n) && (visited[i+1][j+2] == false)){
            abc.push({i+1,j+2});
            h.push(h.front()+1);
            visited[i+1][j+2] = true;
        }

        if(isvalid(i-1,j+2,n) && visited[i-1][j+2] == false){
            abc.push({i-1,j+2});
            h.push(h.front()+1);
            visited[i-1][j+2] = true;
        }

        if(isvalid(i+1,j-2,n) && (visited[i+1][j-2] == false)){
            abc.push({i+1,j-2});
            h.push(h.front()+1);
            visited[i+1][j-2] = true;
        }

        if(isvalid(i-1,j-2,n) && (visited[i-1][j-2] == false)){
            abc.push({i-1,j-2});
            h.push(h.front()+1);
            visited[i-1][j-2] = true;
        }
        
        abc.pop();
        h.pop();
    }
}
int main()
{
    freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    bfs();
	int test;
	cin >> test; 
	while(test--)
    {
        int si,sj;
        cin >> si >> sj;
        si = si - 1;
        sj = sj - 1;
        cout << ans[si][sj] << '\n';
    }
	return 0;
}