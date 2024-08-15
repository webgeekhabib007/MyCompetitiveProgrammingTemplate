#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

#define nl "\n"



int main(int argc, char const *argv[])
{
    ll n,m;cin>>n>>m;
    vector<ll> parent(n),rank(n,1);
    iota(all(parent),0);
    function<ll(ll)> findSet = [&](ll v)->ll{
        if(v==parent[v])return v;
        return parent[v] = findSet(parent[v]);
    };
    auto unionSet = [&](ll a,ll b)->void{
        a = findSet(a),b = findSet(b);
        if(a!=b){
            if(rank[a]<rank[b])swap(a,b);
            parent[b] = a;
            rank[a]+= rank[b];
        }
    };
    for(ll i=0;i<m;i++){
        ll u,v;cin>>u>>v;
        unionSet(u,v);
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ans+= n-rank[findSet(i)];
    }
    cout << ans/2 << nl;
    return 0;
}



// input:
// 5 3
// 0 1
// 2 3
// 0 4

// output:
//6