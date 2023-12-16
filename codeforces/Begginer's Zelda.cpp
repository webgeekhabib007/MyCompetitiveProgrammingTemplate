//Problem Name : Begginer's Zelda
//Solver : Codecrasader036
//Date : 2023-12-17


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



void solve(ll cases=0){
    ll n;
    cin>>n;
    vector<vector<ll>> tree(n + 1);

    for (ll i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // for (ll i = 1; i <= n; ++i) {
    //     cout << i << " -> ";
    //     for (int neighbor : tree[i]) {
    //         cout << neighbor << " ";
    //     }
    //     cout << endl;
    // }

    // Finding vertices with only one neighbor
    ll cnt=0;
    for (int i = 1; i <= n; ++i) {
        if (tree[i].size() == 1) {
            cnt++;
        }
    }
    cout << (cnt+1)/2 << nl;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
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

