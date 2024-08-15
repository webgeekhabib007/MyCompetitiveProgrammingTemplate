#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

#define nl "\n"


int main(int argc, char const *argv[])
{
    ll n,m;cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    vector<bool> vis(n+1,false);
    vector<ll> disc(n+1),low(n+1);
    set<ll> points;
    vector<pair<ll,ll>> bridges;
    ll timer=0;
    function<void(ll,ll)> dfs = [&](ll node,ll par)->void{
        vis[node] = true;
        disc[node] = low[node] = timer++;
        ll no_of_child = 0;
        for(auto to : adj[node]){
            if(to == par)continue;
            if(vis[to]){
                low[node] = min(low[node],disc[to]);
            }else{
                dfs(to,node);
                no_of_child++;
                low[node] = min(low[node],low[to]);
                //cout << "Bridges : " << nl;
                if(low[to] > disc[node]){
                    bridges.push_back({node,to});
                }
                //cout << "Articulation Points : " << nl;
                if(par!=-1 and low[to] >= disc[node]){
                    points.insert(node);
                }
            }
        }
        //corner case for articulation points
        if(par==-1 and no_of_child>=2)points.insert(node);
    };
    dfs(1,-1);
    cout << "Bridges : " << nl;
    for(auto x: bridges)cout << x.first << " " << x.second << nl;
    cout << "Articulation Points : " << nl;
    for(auto x: points)cout << x << " ";

    return 0;
}
// input:
// 7 7
// 1 2
// 2 3
// 3 4
// 4 5
// 4 6
// 4 7
// 5 3

// output:
// Bridges : 
// 4 6
// 4 7
// 2 3
// 1 2
// Articulation Points : 
// 2 3 4 