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
        // http://xorshift.di.unimi.it/splitmix64.c
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




void solve(ll cases=0){
    ll n,k,pa,pb;cin>>n>>k>>pa>>pb;
    vector<ll> p(n),v(n);
    for(auto &x: p)cin>>x;
    for(auto &x: v)cin>>x;
    auto getPath = [&](ll pos)->vector<ll>{
        vector<ll> path = {pos};
        for(ll i=1;i<n;i++){
            path.push_back(p[pos-1]);
            pos = p[pos-1];
        }
        return path;
    };
    vector<ll> path_a = getPath(pa), path_b = getPath(pb);
    debug(path_a,path_b);
    auto getValueAlongPath = [&](vector<ll>& path)->vector<ll>{
        vector<ll> val;
        for(auto x: path){
            val.push_back(v[x-1]);
        }
        return val;
    };
    vector<ll> val1 = getValueAlongPath(path_a),val2 = getValueAlongPath(path_b);
    debug(val1,val2);
    auto getTotal = [&](vector<ll> val)->ll{
        if(k>=n){
            ll sum = 0;
            ll mx_sum = 0;
            for(ll i=0;i<n;i++){
                mx_sum = max(mx_sum,sum + val[i]*(k-i));
                sum+=val[i];
            }
            return mx_sum;
        }else{
            ll sum = 0;
            ll mx_sum = 0;
            for(ll i=0;i<k;i++){
                mx_sum = max(mx_sum,sum + val[i]*(k-i));
                sum+=val[i];
            }
            return mx_sum;
        }
    };
    ll a = getTotal(val1), b = getTotal(val2);
    debug(a,b);
    cout << (a==b? "Draw" : a>b ? "Bodya" : "Sasha") << nl;
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