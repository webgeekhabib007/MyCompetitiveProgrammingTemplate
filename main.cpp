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

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;

ll power(ll base,ll n,ll mod){
    if(n==0)return 1LL;
    if(n==1)return base;
    if(n&1)return (base%mod*power(base,n-1,mod)%mod)%mod;
    ll tmp = power(base,n/2,mod)%mod;
    return (tmp*tmp)%mod;
}

bitset<4000> bs;
vector<ll> prime;
void seive(){
    bs.set();
    bs[0]=0,bs[1]=0;
    for(ll i=4;i<=4000;i+=2)bs[i]=0;
    for(ll i=3;i*i<=4000;i++){
        if(bs[i]){
            for(ll j=i+i;j<=4000;j+=i)bs[j]=0;
        }
    }
    for(ll i=2;i<=4000;i++){
        if(bs[i])prime.push_back(i);
    }
}

const ll mod = 1e9+7;
void solve(ll test_case = 0) {
    ll a,b;cin>>a>>b;
    if((a+b)%2 or a-b<0){
        cout << "NO" << nl;
        return ;
    }
    cout << "YES" << nl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

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

    return 0;
}
