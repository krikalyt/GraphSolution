#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;
typedef pair<long long int,long long int> pi;
int main()
{
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        int n,e;
        cin >> n >> e;
        vector<pair<int,int>> edge[n];
        for(int i=0;i<e;i++){
            int a,b,c;
            cin >> a >> b >> c;
            edge[a-1].push_back({b-1,c});
            edge[b-1].push_back({a-1,c});
        }

        int src;
        cin >> src;
        src = src - 1;
        //dijkastra
        long long int dist[n];
        fill(dist,dist+n,INT_MAX);
        bool visited[n] = {false};
        priority_queue<pi, vector<pi>, greater<pi> > abc; 
        dist[src] = 0;
        abc.push({0,src});
        while(abc.size() > 0){ 
        
            pair<long long int,long long int> temp = abc.top();
            if(visited[temp.second]){
                abc.pop();
                continue;
            }
            visited[temp.second] = true;
            abc.pop();
            for(auto x : edge[temp.second]){
                if(dist[x.first] > x.second + temp.first){
                    dist[x.first] = x.second + temp.first;
                }
                if(visited[x.first] == false){
                    abc.push({dist[x.first],x.first});
                }
            }
        }

        for(int i=0;i<n;i++){
            if(i == src)
                continue;
            if(dist[i] == INT_MAX){
                cout << -1 << ' ';
                continue;
            }
            cout << dist[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}