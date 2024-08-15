#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>


using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define nl "\n"
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
  #define debug(x...)
#endif

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template<typename T,typename sortBy=less<T> >
using order_set = tree<T,null_type,sortBy,rb_tree_tag,tree_order_statistics_node_update> ;

ll power(ll base,ll n,ll mod){
    if(n==0)return 1LL;
    if(n==1)return base;
    if(n&1)return (base%mod*power(base,n-1,mod)%mod)%mod;
    ll tmp = power(base,n/2,mod)%mod;
    return (tmp*tmp)%mod;
}


const ll mod = 1e9+7;
class Node{
    public:
    ll u,v,w;
    Node(){};
    Node(ll _u,ll _v,ll _w): u(_u),v(_v),w(_w){};
    operator<(Node &other){
        if(w != other.w)return w < other.w;
        if(u != other.u)return u < other.u;
        return v < other.v;
    }
};
void solve(ll test_case = 0) {
    ll n,m;cin>>n>>m;
    vector<Node> arr;
    for(ll i=0;i<m;i++){
        ll u,v,w;cin>>u>>v>>w;
        arr.push_back(Node(u,v,w));
    }
    sort(all(arr));
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
    ll ans = 0;
    for(auto x: arr){
        if(findSet(x.u) != findSet(x.v)){
            unionSet(x.u,x.v);
            ans+= x.w;
        }
    }
    cout << ans << nl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    auto begin = chrono::high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        //freopen("error.txt", "w", stderr);
    #endif

    //#define TEST_CASE

    #ifdef TEST_CASE
        ll test;
        cin >> test;
        for (ll cases = 0; cases < test; cases++)
            solve(cases);
    #else 
        solve();

    #endif
    auto end = chrono::high_resolution_clock::now();
    cerr << "--->>  Time elapsed : " 
         << chrono::duration_cast<chrono::milliseconds>(end-begin).count() 
         << " ms.  <<---" 
         << nl;
    return 0;
}

//input
// 4 6
// 0 1 1
// 1 3 3 
// 3 2 4
// 2 0 2
// 0 3 2
// 1 2 2
// output:
//5