//░░░░░░░░░░ // You have struggled your way here with no guidance from anyone,keep the faith
//░░░░░░░░▄▐░▄▄█████▄▄     //You have practiced a hell lot of questions,have faith in yourself
//░░░░░░▄█████████████▄▀▄▄▄▄▄    //Don't just stare at the problem use that damn pen and paper
//░░░░░█████████████████▄██████ // write down whats in ur head !
//░░░░████▐█████▌████████▌█████▌
//░░░████▌█████▌█░████████▐▀██▀
//░▄█████░█████▌░█░▀██████▌█▄▄▀▄
//░▌███▌█░▐███▌▌░░▄▄░▌█▌███▐███░▀
//▐░▐██░░▄▄▐▀█░░░▐▄█▀▌█▐███▐█
//░░███░▌▄█▌░░▀░░▀██░░▀██████▌
//░░░▀█▌▀██▀░▄░░░░░░░░░███▐███
//░░░░██▌░░░░░░░░░░░░░▐███████▌
//░░░░███░░░░░▀█▀░░░░░▐██▐███▀▌
//░░░░▌█▌█▄░░░░░░░░░▄▄████▀░▀
//░░░░░░█▀██▄▄▄░▄▄▀▀▒█▀█░▀
//░░░░░░░░░▀░▀█▀▌▒▒▒░▐▄▄
//░░░░░░░░▄▄▀▀▄░░░░░░▄▀░▀▀▄▄
//░░░░░░▄▀░▄▀▄░▌░░░▄▀░░░░░░▄▀▀▄
//░░░░░▐▒▄▀▄▀░▌▀▄▄▀░░░░░░▄▀▒▒▒▐
//░░░░▐▒▒▌▀▄░░░░░▌░░░░▄▄▀▒▐▒▒▒▒▌
//░░░▐▒▒▐░▌░▀▄░░▄▀▀▄▀▀▒▌▒▐▒▒▒▒▐▐
//░░░▌▄▀░░░▄▀░█▀▒▒▒▒▀▄▒▌▐▒▒▒▒▒▌▌
//░░▄▀▒▐░▄▀░░░▌▒▐▒▐▒▒▒▌▀▒▒▒▒▒▐▒▌
 
 
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
 
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
using namespace std;
 
 
 
typedef long long int ll;
typedef unsigned long long int ull;
 
#define nl "\n"
#define all(v) (v).begin(),(v).end()
 
 
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
 
 
#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
  #define debug(x...)
#endif
 
const ll MOD = 1e9 + 7;
const ll MAX_N = 1e6;
 
vector<ll> fact(MAX_N + 1), inv_fact(MAX_N + 1);
 
// Function to compute power using binary exponentiation
ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
 
// Function to precompute factorials and their inverses
void precompute_factorials() {
    fact[0] = 1;
    for (ll i = 1; i <= MAX_N; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
 
    inv_fact[MAX_N] = power(fact[MAX_N], MOD - 2, MOD); // Fermat's inverse
    for (ll i = MAX_N - 1; i >= 0; --i) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}
 
// Function to compute nCr using precomputed factorials and inverses
ll nCr(ll n, ll r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD) % MOD;
}

// Function to preprocess the string to insert '#' characters
string preprocess(const string &s) {
    int n = s.size();
    if (n == 0) return "^$";
    string ret = "^";
    for (int i = 0; i < n; i++) {
        ret += "#" + s.substr(i, 1);
    }
    ret += "#$";
    return ret;
}

// Function to find the longest palindromic substring using Manacher's Algorithm
string longestPalindromicSubstring(const string &s) {
    string T = preprocess(s);
    int n = T.size();
    vector<int> P(n, 0);
    int C = 0, R = 0; // current center and right edge of the rightmost palindrome

    for (int i = 1; i < n - 1; i++) {
        int mirr = 2 * C - i; // mirror of i with respect to center C

        if (R > i) {
            P[i] = min(R - i, P[mirr]);
        }

        // Expand around center i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            P[i]++;
        }

        // Update center and right edge
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Find the maximum element in P
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - 1 - maxLen) / 2;
    return s.substr(start, maxLen);
}
 

ll findMaxHeight(const vector<string> &grid, ll n, ll m) {
    ll max_height = 0;
    for (string row : grid) {
        ll flag = 0;
        ll height_count = 0;
        for (ll j = 0; j <= m; ++j) {
            if (row[j] == '#') {
                height_count++;
                if (flag == 0) {
                    flag = 1;
                }
            } else if (flag == 1) {
                max_height = max(height_count, max_height);
                flag = 0;
                height_count = 0;
            }
        }
    }
    return max_height;
}


pair<ll, ll> getEdges(const vector<string> &grid, ll n, ll m) {
    ll left_edge = m + 1;
    ll right_edge = -1;
    ll max_height = 0;
    for (string row : grid) {
        ll flag = 0;
        ll height_count = 0;
        for (ll j = 0; j <= m; ++j) {
            if (row[j] == '#') {
                height_count++;
                if (flag == 0) {
                    flag = 1;
                    left_edge = min(left_edge, j);
                }
            } else if (flag == 1) {
                right_edge = max(right_edge, j - 1);
                flag = 0;
            }
        }
        max_height = max(height_count, max_height);
    }
    return {left_edge, right_edge};
}

ll getHeight(const vector<string> &grid, ll n, ll m, ll max_height) {
    ll answer = -1;
    for (ll i = 0; i < n; ++i) {
        ll height_count = 0;
        for (ll j = 0; j <= m; ++j) {
            if (grid[i][j] == '#') {
                height_count++;
                if (height_count == max_height) {
                    answer = i;
                    break;
                }
            }
        }
    }
    return answer;
}



void solve(ll cases = 0) {
    ull n;cin>>n;
    vector<ll> v(n);
    for(auto &x: v)cin>>x;
    debug(v);
    set<ll> st;
    ull sum = 0,cnt = 0;
    for(auto x: v){
        st.insert(sum);
        sum+=x;
        auto it = st.end();
        ll top = *(--it);
        cnt+= (top == (sum - top))
    }
    cout << cnt << nl;
}
 
 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        //freopen("error.txt","w",stderr);
    #endif
 
        #define TEST_CASE
 
        #ifdef TEST_CASE
            ll test;
            cin>>test;
            for(ll cases=0;cases<test;cases++)
                solve(cases);
        #else 
            solve();
 
        #endif
  
  return 0;
}