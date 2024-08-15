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


const ll mod = 1e9+7;
const ll N = 1e7 + 10;
ll grundy[N];

void pre() {
    memset(grundy, -1, sizeof grundy);
    grundy[0] = 0;
    grundy[1] = 1;

    ll cnt = 0;
    for (ll i = 2; i < N; i++) {
        if (grundy[i] == -1) {
            cnt++;
            if (i == 2) cnt = 0;
            if (i == 3) cnt = 2;
            for (ll j = i; j < N; j += i) {
                if (grundy[j] == -1) grundy[j] = cnt;
            }
        }
        if (grundy[i] == -1) {
            cnt++;
        }
    }
}

void solve(ll test_cases=0) {
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    auto get = [&](string p)->ll{
        ll len = p.size();
        ll mn = LLONG_MAX;
        for(ll i=1;i<len/2;i++){
            if(i%2==0){
                ll cnt = len/i;
                string tmp = "";
                for(ll j=0;j<cnt;i++){
                    tmp+= p.substr(i*j,i*(j+1));
                }
                ll cmp_len = 0;
                for(ll j=0;j<cnt;j+=2){
                    string s1 = tmp.substr(0,i);
                    string s2 = tmp.substr(i,2*i);
                }
            }
        }
    };
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
