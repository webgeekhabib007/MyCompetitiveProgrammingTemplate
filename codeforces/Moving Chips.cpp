//Problem Name : Moving Chips
//Solver : Codecrasader036
//Date : 2024-02-23


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

string problem_name = "\"Moving Chips\"";


const ll mod = 1e9+7;
void solve(ll cases=0){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(auto &x: v)cin>>x;
    ll l=0,r=n-1;
    while(v[l]==0)l++;
    while(v[r]==0)r--;
    ll cnt=0;
    for(ll i=l;i<=r;i++){
        if(v[i]==0)cnt++;
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