#include <bits/stdc++.h>
using namespace std;

int id = 0;
void find(vector<int> adj[], stack<int> &st, int index[], int lowlink[],
          bool onstack[], int i) {
    index[i] = lowlink[i] = id;
    st.push(i);
    onstack[i] = true;
    id++;
    // cout << i << ' ';
    
    for(int x : adj[i]){
        if(index[x] == -1){
            find(adj,st,index,lowlink,onstack,x);
            lowlink[i] = min(lowlink[x],lowlink[i]);
        }else{
            if(x == i){
                continue;
            }
            if(onstack[x] == true){
                lowlink[i] = min(lowlink[x],lowlink[i]);
            }
        }
    }
    
    if(index[i] == lowlink[i]){
        
        while(st.size() > 0 and st.top() != i){
            cout << st.top() << ' ';
            onstack[st.top()] = false;
            st.pop();
        }
        cout << st.top();
        onstack[st.top()] = false;
        st.pop();
        cout << ',';
    }
}

int main()
{
    int test;
    cin >> test;
    while(test--){
        int n,e;
        cin >> n >> e;
        vector<int> edge[n];
        for(int i=0;i<e;i++){
            int a,b;
            cin >> a >> b;
            edge[a].push_back(b);
        }

        bool onstack[n];
        int index[n];
        int lowlink[n];
        stack<int> sc;

        for(int i=0;i<n;i++){
            onstack[i] = false;
            index[i] = -1;
            lowlink[i] = -1;
        }

        for(int i=0;i<n;i++){
            if(index[i] == -1){
                find(edge,sc,index,lowlink,onstack,i);
            }
        }
        cout << '\n';
    }
    return 0;
}