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
    size_t operator()(pair<ll,ll> x) const {
        return x.first*31 + x.second*31*31;
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

ll modinv(ll base,ll mod){
    return power(base,mod-2,mod);
}

const ll mod = 1e9+7;
void solve(ll cases=0){
    ll n,q;cin>>n>>q;
    vector<ll> v(n);
    for(auto&x : v)cin>>x;
    unordered_map<ll,ll,> mp;
    for(ll i=1;i<=n;i++){
        ll tmp = (i-1)*(n-i+1) + (n-i);
        mp[tmp]++;
        if(i<n){
            ll dif = (v[i] - v[i-1])-1;

            if(dif>0){
                tmp = i*(n-i);
                mp[tmp]+= dif;
            }
        }
    }
    while(q--){
        ll inp;cin>>inp;
        cout << mp[inp] << " ";
    }cout << nl;
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

    #define TEST_CASE

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
