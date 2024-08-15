#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

#define nl "\n"
#define all(v) (v).begin(),(v).end()


int main(int argc, char const *argv[])
{
    ll n;cin>>n;
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll u,v;cin>>u>>v;
        //u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> depth(n+1,0);
    function<void(ll,ll)> dfs = [&](ll curr,ll par)->void{
        for(auto to: adj[curr]){
            if(to == par)continue;
            depth[to] = depth[curr]+1;
            dfs(to,curr);
        }
    };
    dfs(1,-1);
    ll mx = *max_element(all(depth));
    ll k = log2(mx)+1;
    vector<vector<ll>> parent(n+1,vector<ll>(k+1));
    function<void(ll,ll)> calc_par = [&](ll curr,ll par)->void{
        parent[curr][0] = par;
        for(ll i = 1;i<k;i++){
            parent[curr][i] = parent[parent[curr][i-1]][i-1];
        }
        for(auto x: adj[curr]){
            if(par == x)continue;
            calc_par(x,curr);
        }
    };
    calc_par(1,0);
    auto jump = [&](ll node,ll val)->ll{
        ll par = node;
        while(val>0){
            ll t = log2(val&-val);
            par = parent[par][t];
            val-= val&-val;
        }
        return par;
    };
    auto calc_lca = [&](ll u,ll v)->ll{
        if(u==v)return u;
        if(depth[u] > depth[v])swap(u,v);
        ll diff = depth[v] - depth[u];
        v = jump(v,diff);
        assert(depth[u] == depth[v]);
        ll left = 1,right = mx;
        ll lca = u;
        while(left<=right){
            ll mid = (left+right)/2;
            ll jump_u = jump(u,mid),jump_v = jump(v,mid);
            if(jump_u == jump_v)right = mid-1,lca = jump_u;
            else left = mid+1;
        }
        return lca;
    };
    cout << calc_lca(18,16);
    assert(calc_lca(7,7) == 7);
    assert(calc_lca(7,16) == 1);
    assert(calc_lca(1,1) == 1);
    assert(calc_lca(7,17) == 1);
    assert(calc_lca(13,16) == 12);

    return 0;
}
// input:
// 19
// 1 2
// 1 3
// 2 4
// 2 5
// 3 10
// 3 11
// 5 6
// 6 7
// 6 8
// 6 9
// 10 17
// 17 18
// 17 19
// 11 12
// 12 13
// 12 14
// 12 15
// 15 16

// output:
//3