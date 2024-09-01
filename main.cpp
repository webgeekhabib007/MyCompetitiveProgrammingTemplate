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
void solve(ll test_cases=0) {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        if (n % 2 != 0) {
            if (n == 1) {
                cout << 1 << endl;
                return;
            }

            ll best = 1e9;
            vector<ll> ec(26, 0), oc(26, 0);
            for (ll i = 0; i < n - 1; i++) {
                if (i % 2 == 0) ec[s[i] - 'a']++;
                else oc[s[i] - 'a']++;
            }

            vector<ll> eca(26, 0), oca(26, 0);
            ll em = *max_element(ec.begin(), ec.end()), om = *max_element(oc.begin(), oc.end());
            best = min(best, (n / 2 - em) + (n / 2 - om));

            for (ll i = n - 2; i >= 0; i--) {
                if (i % 2 == 0) { ec[s[i] - 'a']--; eca[s[i + 1] - 'a']++; }
                else { oc[s[i] - 'a']--; oca[s[i + 1] - 'a']++; }

                vector<ll> emc = ec, omc = oc;
                for (ll j = 0; j < 26; j++) {
                    emc[j] += eca[j];
                    omc[j] += oca[j];
                }
                em = *max_element(emc.begin(), emc.end());
                om = *max_element(omc.begin(), omc.end());
                best = min(best, (n / 2 - em) + (n / 2 - om));
            }
            cout << (n < 2 ? best + 2 : best + 1) << endl;

        } else {
            vector<ll> ec(26, 0), oc(26, 0);
            for (ll i = 0; i < n; i++) {
                if (i % 2 == 0) ec[s[i] - 'a']++;
                else oc[s[i] - 'a']++;
            }

            ll em = *max_element(ec.begin(), ec.end()), om = *max_element(oc.begin(), oc.end());
            cout << (n / 2 - em) + (n / 2 - om) << endl;
        }
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
