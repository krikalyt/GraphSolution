#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> abc;
    abc.push({1,2});
    abc.push({2,2});
    abc.push({3,5});
    while(abc.size()){
        cout << (abc.top()).first << ' ';
        abc.pop();
    }
    cout << '\n';
    return 0;
}