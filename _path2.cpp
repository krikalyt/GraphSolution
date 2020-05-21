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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test; 
	while(test--)
    {
        int n;
        n = 1000;
        int arr[n][n];
        int si,sj;
        int di,dj;
        
        cin >> si >> sj;
        si = si - 1;
        sj = sj - 1;
        di = 0;
        dj = 0;

        bool visited[n][n];
        for(int i=0;i<n;i++){
            fill(visited[i],visited[i]+n,false);
        }
      
        queue<pair<int,int>> abc;
        abc.push({si,sj});
        queue<int> h;
        h.push(0);
        visited[si][sj] = true;
        while(abc.size() > 0){
            
            auto temp = abc.front();
            int i = temp.first;
            int j = temp.second;
            if(i == di && j == dj){
                cout << h.front() << '\n';
                break;
            }

            bool a1 = isvalid(i+2,j+1,n);
            bool a2 = isvalid(i+2,j-1,n);
            bool b1 = isvalid(i-2,j+1,n);
            bool b2 = isvalid(i-2,j-1,n);

            bool c1 = isvalid(i+1,j+2,n);
            bool c2 = isvalid(i-1,j+2,n);
            bool d1 = isvalid(i+1,j-2,n);
            bool d2 = isvalid(i-1,j-2,n);

            if(a1 and !visited[i+2][j+1]){
                abc.push({i+2,j+1});
                visited[i+2][j+1] = true;
                h.push(h.front() + 1);
            }

            if(a2 and !visited[i+2][j-1]){
                abc.push({i+2,j-1});
                visited[i+2][j-1] = true;
                h.push(h.front() + 1);
            }

            if(b1 and !visited[i-2][j+1]){
                abc.push({i-2,j+1});
                visited[i-2][j+1] = true;
                h.push(h.front() + 1);
            }

            if(b2 and !visited[i-2][j-1]){
                abc.push({i-2,j-1});
                visited[i-2][j-1] = true;
                h.push(h.front() + 1);
            }

            if(c1 and !visited[i+1][j+2]){
                abc.push({i+1,j+2});
                visited[i+1][j+2] = true;
                h.push(h.front() + 1);
            }

            if(c2 and !visited[i-1][j+2]){
                abc.push({i-1,j+2}); 
                visited[i-1][j+2] = true;
                h.push(h.front() + 1);
            }

            if(d1 and !visited[i+1][j-2]){
                abc.push({i+1,j-2}); 
                visited[i+1][j-2] = true;
                h.push(h.front() + 1);
            }

            if(d2 and !visited[i-1][j-2]){
                abc.push({i-1,j-2}); 
                visited[i-1][j-2] = true;
                h.push(h.front() + 1);
            }

            abc.pop();
            h.pop();
        }
    }
	return 0;
}