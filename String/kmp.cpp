#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

#define nl "\n"


int main(int argc, char const *argv[])
{
    string s = "seventy seven";
    string p = "seven";
    ll n = s.size(),m = p.size();
    auto KMPpreprocess = [&](string pat)->vector<ll>{
        vector<ll> reset(pat.size());
        reset[0] = -1;
        ll i=0,j=-1,size = pat.size();
        while(i < size){
            while(j>=0 and pat[i]!=pat[j])j = reset[j];
            i++,j++;
            reset[i] = j;
        }
        return reset;
    };
    vector<ll> reset = KMPpreprocess(p);
    auto KMPsearch = [&]()->void{
        ll i=0,j=0;
        while(i<n){
            while(j>=0 and s[i]!=p[j]) j = reset[j];
            i++,j++;
            if(j==m){
                cout << "P is found at " << i-j << nl;
            }
        }
    };
    KMPsearch();
    return 0;
}
