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

ll log2_custom(ll x) {
    ll res = 0;
    while (x >>= 1) ++res;
    return res;
}

class Range {
public:
    ll l, r, min_p, max_p;
    bool operator<(const Range &other) const { return l < other.l; }
};

ll query_min(const vector<vector<ll>> &min1, ll l, ll r) {
    ll k = log2_custom(r - l + 1);
    return min(min1[k][l], min1[k][r - (1 << k) + 1]);
}

ll query_max(const vector<vector<ll>> &max1, ll l, ll r) {
    ll k = log2_custom(r - l + 1);
    return max(max1[k][l], max1[k][r - (1 << k) + 1]);
}

void solve(ll cases=0) {
    ll n, q;
    cin >> n >> q;
    vector<ll> p(n + 1);
    for (ll i = 1; i <= n; i++) cin >> p[i];

    ll LOG = 21;
    vector<vector<ll>> min1(LOG, vector<ll>(n + 1)), max1(LOG, vector<ll>(n + 1));
    for (ll i = 1; i <= n; i++) min1[0][i] = max1[0][i] = p[i];

    for (ll k = 1; k < LOG; k++)
        for (ll i = 1; i + (1 << k) - 1 <= n; i++) {
            min1[k][i] = min(min1[k - 1][i], min1[k - 1][i + (1 << (k - 1))]);
            max1[k][i] = max(max1[k - 1][i], max1[k - 1][i + (1 << (k - 1))]);
        }

    string s;
    cin >> s;
    set<Range> ranges;
    ll cnt = 0, l = 1;

    for (ll i = 2; i <= n; i++) {
        if (s[i - 2] == 'R' || s[i - 1] == 'L') continue;
        ll r_i = i - 1, mn = query_min(min1, l, r_i), mx = query_max(max1, l, r_i);
        if (mn != l || mx != r_i) cnt++;
        ranges.insert({l, r_i, mn, mx});
        l = i;
    }

    ll r_i = n, mn = query_min(min1, l, r_i), mx = query_max(max1, l, r_i);
    if (mn != l || mx != r_i) cnt++;
    ranges.insert({l, r_i, mn, mx});

    auto process = [&](ll a, ll b, bool add_joint) {
        if (a < 1 || b > n || a >= b) return;
        if (add_joint) {
            auto it1 = ranges.end(), it2 = ranges.end();
            auto it_a = ranges.lower_bound({a, 0, 0, 0});
            it1 = (it_a != ranges.end() && it_a->l == a) ? it_a : (it_a == ranges.begin() ? it_a : prev(it_a));
            if (!(it1->l <= a && a <= it1->r)) it1 = ranges.end();

            auto it_b = ranges.lower_bound({b, 0, 0, 0});
            it2 = (it_b != ranges.end() && it_b->l == b) ? it_b : (it_b == ranges.begin() ? it_b : prev(it_b));
            if (!(it2->l <= b && b <= it2->r)) it2 = ranges.end();

            if (it1 != ranges.end() && it2 != ranges.end() && it1 != it2) {
                if (it1->min_p != it1->l || it1->max_p != it1->r) cnt--;
                if (it2->min_p != it2->l || it2->max_p != it2->r) cnt--;
                ll new_l = min(it1->l, it2->l), new_r = max(it1->r, it2->r);
                ll new_mn = query_min(min1, new_l, new_r), new_mx = query_max(max1, new_l, new_r);
                if (new_mn != new_l || new_mx != new_r) cnt++;
                ranges.erase(it1); ranges.erase(it2);
                ranges.insert({new_l, new_r, new_mn, new_mx});
            }
        } else {
            auto it = ranges.lower_bound({a, 0, 0, 0});
            it = (it == ranges.end() || it->l > a) ? (it == ranges.begin() ? it : prev(it)) : it;
            if (it->l <= a && a <= it->r && it->l != it->r) {
                Range left = {it->l, a, query_min(min1, it->l, a), query_max(max1, it->l, a)};
                Range right = {a + 1, it->r, query_min(min1, a + 1, it->r), query_max(max1, a + 1, it->r)};
                if (it->min_p != it->l || it->max_p != it->r) cnt--;
                if (left.min_p != left.l || left.max_p != left.r) cnt++;
                if (right.min_p != right.l || right.max_p != right.r) cnt++;
                ranges.erase(it); ranges.insert(left); ranges.insert(right);
            }
        }
    };

    while (q--) {
        ll idx;
        cin >> idx;
        char old_s = s[idx - 1];
        s[idx - 1] = (s[idx - 1] == 'L') ? 'R' : 'L';

        bool old_joint1 = (old_s == 'L') || (idx - 1 >= 1 && s[idx - 2] == 'R');
        bool new_joint1 = (s[idx - 1] == 'L') || (idx - 1 >= 1 && s[idx - 2] == 'R');
        if (old_joint1 != new_joint1) process(idx - 1, idx, new_joint1);

        bool old_joint2 = (old_s == 'R') || (idx + 1 <= n && s[idx] == 'L');
        bool new_joint2 = (s[idx - 1] == 'R') || (idx + 1 <= n && s[idx] == 'L');
        if (old_joint2 != new_joint2) process(idx, idx + 1, new_joint2);

        cout << (cnt == 0 ? "YES\n" : "NO\n");
    }
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
