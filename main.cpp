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
        return x.first * 31 + x.second * 31 * 31;
    }
};

template<typename T, typename sortBy = less<T>>
using order_set = tree<T, null_type, sortBy, rb_tree_tag, tree_order_statistics_node_update>;

ll power(ll base, ll n, ll mod) {
    if (n == 0) return 1LL;
    if (n == 1) return base;
    if (n & 1) return (base % mod * power(base, n - 1, mod) % mod) % mod;
    ll tmp = power(base, n / 2, mod) % mod;
    return (tmp * tmp) % mod;
}

ll modinv(ll base, ll mod) {
    return power(base, mod - 2, mod);
}

const ll mod = 998244353;

void solve(ll cases=0) {
    ll n,m;cin>>n>>m;
    vector<set<ll>>adj(n + 1);
    vector<bool> vis(n + 1, 0);

    auto is = [&](ll u, ll v) -> bool {
        return adj[u].find(v)!= adj[u].end();
    };
    for (ll i = 1; i <= m; i++) {
        ll u,v;cin>>u>>v;
        adj[u].insert(v), adj[v].insert(u);
    }

    vector<tuple<ll, ll, ll>> ans;
    for (ll i = 1; i <= n; i++) {
        while (adj[i].size() > 1) {
            ll u = *adj[i].begin(); adj[i].erase(u);
            ll v = *adj[i].begin(); adj[i].erase(v);
            ans.push_back({u, v, i});
            adj[u].erase(i); adj[v].erase(i);
            if (is(u, v))adj[u].erase(v), adj[v].erase(u);
            else adj[u].insert(v), adj[v].insert(u);
        }
    }
    ll u = 0, v = 0;
    for (ll i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            u = i; v = *adj[i].begin();
            adj[i].erase(v); vis[u] = vis[v] = 1;
            break;
        }
    }

    if(u){
        for(ll i = 1; i <= n; i++) {
            if (vis[i]) continue;
            if (adj[i].empty()) ans.push_back({u, v, i}),vis[i] = 1, v = i;
            else {
                ll p = *adj[i].begin();
                vis[i] = vis[p] = 1;
                ans.push_back({u, i, p});
            }
        }
    }

    cout << ans.size() << nl;
    for (auto& r : ans) cout << get<0>(r) << " " << get<1>(r) << " " << get<2>(r) << nl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    auto begin = chrono::high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
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
         << chrono::duration_cast<chrono::milliseconds>(end - begin).count() 
         << " ms.  <<---" 
         << nl;
    return 0;
}
