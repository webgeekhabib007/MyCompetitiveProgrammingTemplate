//Problem Name : Insert and Equalize
//Solver : Codecrasader036
//Date : 2024-03-08



////////////////////////////////////////////////////////////////////////
//OOOOOOOOOOOOOOOOOOOOOOOkxdoollooooooollodkkOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOkdoc:::ccccccccccccc:::clodxkOOOOOOOOOkOOOOOOOOOO//
//OOOOOOOOOOOOOOkxdlc:::cldddddddddddddddddocc:::cldkOOOkOOOkOOOOOOOOO//
//OOOOOOOOOOOOkdc;:cloddddddddddddddddddddddddddol:;coxkkOOkkOOOOOOOOO//
//OOOOOOOOOOkdc;:ldddddddddddddddddddddddddddddddddoc::lxkOOOOOOOOOOOO//
//OOOOOOOOkko;;lddddddddddddddddddddddddddddddddddddddl::lxkOOOOOOOOOO//
//OOOOOOOOko;;odddddddddddddddddddddddddddddddddddddddddl::okOOOOOOOOO//
//OOOOOOOko:;ldddddddddddddddddddddddddddddddddddddddddddo:;okOOOOOOOO//
//OOOOOkkd:;ldddddddddddddddddddddddddddddddddddddddddddddo:;dOOOOOOOO//
//OOOOOkxo;;dddddddddddddddddddddddddddddddddddddddddddddddl;lkOOOOOOO//
//OOOOOkxc,cdddddddddddddddddddddddddddddddddddddddddddddddo;:xOOOOOOO//
//OOOOOkd:,lddddddddddddddddddddddddddddddddddddddddddddddddc;lkOOOOOO//
//OOOOkkd:;odddddddddddddddddddddddddddddddddddddddddddddddddc;cxOOOOO//
//OOOOkxl,:dddddddddddddddddddddddddddddddddddddddddddddddddddc;dOOOOO//
//OOOkkxc,cdddddddddddddddddddddddddddddddddddddddddddddddddddc;okOOOO//
//OOOOkxc;lddddddddddddddddddddddl:;,:ldddddddddddddddolccodddl;lkOOOO//
//OOOOkxl;cdddddddddddddddddddddo,    'oddddddddoooddo;.  'lddl;lkOOOO//
//OOOOkkdc,:ddddddddddddddddddddoc'..':ddddddddo;.'lddc...,oddl;lkOOOO//
//OOOOOkxd:;ldddddddddddddddddddddddoddddddddddo;  'oddoloddddo::dOOOO//
//OOOOOOkxl;:odddddddoodddddddddddddddddddddddddl'  ;odddddddddl;ckOOO//
//OOOOOOkkxl;:ldddddo:;odddddddddddddddddddddddddc. .cdddddddddo::xOOO//
//OOOOOOOOkxdc;cddddo;;ddddddddddddddddddddddddddo,  ,oddddddddo;ckOOO//
//OOOOOOOOOkxdc,cdddo;,lddddddddddddddddddddddddddc. .lddddddddc;okOOO//
//OOOOOOOOOOkxl,;ddddo;;oddddddddddddddddlc:clllcl:.  ;oddddddl;ckOOOO//
//OOOOOOOOOOkxo;;oddddl,;oddddddddddddddo,.  ...      'ldddddo;:xOOOOO//
//OOOOOOOOOOkxd;,oddddo:',lddddddddddddddoc::;;;;;;;;;cdddddl;:dOOOOOO//
//OOOOOOOOOOkkd;,lddddl:::;:ldddddddddolllllllooooooooddddl::okOOOOOOO//
//OOOOOOOOOOkko;;oddxdl:ldl:;:oddddddd;..  ............:oo::xOOOOOOOOO//
//OOOOOOOOOOkd:,cdddddl:odddl:;cldddddl:;;;;,,,,'''''',col;ckOOOOOOOOO//
//OOOOOOOOOkxl,;ddddddllddddddl:;;codddddddddddddddddddoc;:dOOOOOOOOOO//
//OOOOOOOOOkxc,cddddddddddddddddoc;;:coddddddddddddddoc::okOOOOOOOOOOO//
//OOOOOOOOkxl::oddddddddddddddddddoc::::clodddddooc::ccokOOOOOOOOOOOOO//
//OOOOOOOkxc;cddddddddddddddddddddddddol:;:::::;;:ccdkOOOOOOOOOOOOOOOO//
//OOOOkxdc::ldddddddddddddddddddddddddddl:cllll;;dOOOOOOOOOOOOOOOOOOOO//
//OOOkdlcclddddddddddddddddddddddddddddddllodddoldkOOOOOOOOOOOOOOOOOOO//
//OOOOkkkkxxxxdddddddddddddddoooodddddddooddxxkkkOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOkkkkkxxxxxxxxxxxxdlccccloolclloxkOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOkkkdolllldkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
////////////////////////////////////////////////////////////////////////


#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define nl "\n"
#define all(v) (v).begin(),(v).end()

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
  #define debug(x...)
#endif

string problem_name = "\"Insert and Equalize\"";

const ll mod = 100;



void solve(ll cases=0){
    ll n;cin>>n;
    vector<ll> v(n);
    ll mn = 0;
    for(auto &x: v){
        cin>>x;
        mn = min({mn,x});
    }
    mn = abs(mn);
    ll mx = 0;
    map<ll,ll> mp;
    for(auto &x: v){
        x+= mn;
        mx = max(mx,x);
        mp[x]++;
    }
    ll gcd = 0LL;
    for(auto &x: v){
        gcd = __gcd(gcd,x);
    }
    ll ans = 0;
    gcd = max(gcd,1LL);
    for(auto &x: v){
        ans+= (mx-x)/gcd;
    }
    ll cp = mx;
    mx -= gcd;
    while(mx>=0){
        if(mp.find(mx) == mp.end()){
            ans+= (cp - mx)/gcd;
            break;
        }else{
            mx-=gcd;
        }
    }
    debug(ans);
    cout << ans << nl;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
        string cmd = "python main.py "+problem_name;
        system(cmd.c_str());
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