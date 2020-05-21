#include<bits/stdc++.h>
using namespace std;
bool isvalid(int i,int j,int n){
    if(i < 0 || i >= n){
        return false;
    }
    if(j < 0 || j >= n){
        return false;
    }
    return true;
}
int main()
{
    freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test; 
	while(test--)
    {
        int n;
        cin >> n;
        int arr[n][n];
        int si,sj;
        int di,dj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> arr[i][j];
                if(arr[i][j] == 1){
                    si = i;
                    sj = j;
                }
                
                if(arr[i][j] == 2){
                    di = i;
                    dj = j;
                }
            }
        }

        bool visited[n][n];
        for(int i=0;i<n;i++){
            fill(visited[i],visited[i]+n,false);
        }
        
        bool found = false;
        queue<pair<int,int>> abc;
        abc.push({si,sj});
        while(abc.size() > 0){
            auto temp  = abc.front();
            int i = temp.first;
            int j = temp.second;
            visited[i][j] = true;
            if(i == di && j == dj){
                found = true;
                break;
            }
            
            if(isvalid(i+1,j,n) && visited[i+1][j] == false && (arr[i+1][j] == 2 or arr[i+1][j] == 3)){
                abc.push({i+1,j});
            }
            if(isvalid(i-1,j,n) && visited[i-1][j] == false && (arr[i-1][j] == 2 or arr[i-1][j] == 3)){
                abc.push({i-1,j});
            }
            if(isvalid(i,j+1,n) && visited[i][j+1] == false && (arr[i][j+1] == 2 or arr[i][j+1] == 3)){
                abc.push({i,j+1});
            }
            if(isvalid(i,j-1,n) && visited[i][j-1] == false && (arr[i][j-1] == 2 or arr[i][j-1] == 3)){
                abc.push({i,j-1});
            }
            abc.pop();
        }
        
        cout  << found << '\n';
    }
	return 0;
}