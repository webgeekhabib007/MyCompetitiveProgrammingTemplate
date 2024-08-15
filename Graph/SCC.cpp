#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

#define nl "\n"
#define all(v) (v).begin(),(v).end()


int main(int argc, char const *argv[])
{
    ll n,m;cin>>n>>m;
    vector<vector<ll>> adj(n),adj1(n);
    for(ll i=0;i<m;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v); // origianl graph
        adj1[v].push_back(u); // reverse graph
    }
    stack<ll> ordering; 
    vector<ll> vis(n,false);
    function<void(ll)> dfs1 = [&](ll curr)->void{
        vis[curr] = true;
        for(auto x: adj[curr]){
            if(!vis[x])dfs1(x);
        }
        ordering.push(curr);
    };
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            dfs1(i);
        }
    }
    assert(ordering.size() == n);
    vector<vector<ll>> scc;
    vis.assign(n,false);
    vector<ll> tmp;
    function<void(ll)> dfs2 = [&](ll curr)->void{
        tmp.push_back(curr);
        vis[curr] = true;
        for(auto x : adj1[curr]){
            if(!vis[x])dfs2(x);
        }
    };
    while(!ordering.empty()){
        ll t = ordering.top();
        ordering.pop();
        tmp.clear();
        if(!vis[t])dfs2(t),scc.push_back(tmp);
    }
    for(auto x: scc){
        for(auto y : x)cout << y << " ";
        cout << nl;
    }
    assert(scc.size() == 3);

    return 0;
}
// input:
// 7 8
// 0 2
// 2 1
// 1 0
// 0 3
// 3 5
// 5 6
// 6 3
// 3 4
// output:
// 0 1 2 
// 3 6 5 
// 4 