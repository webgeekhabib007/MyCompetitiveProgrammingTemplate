#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 1e7 + 10;
ll grundy[N];

void solve() {
    memset(grundy, -1, sizeof grundy);
    grundy[0] = 0;
    grundy[1] = 1;

    ll cnt = 0;
    for (ll i = 2; i < N; i++) {
        if (grundy[i] == -1) {
            cnt++;
            if (i == 2) cnt = 0;
            if (i == 3) cnt = 2;
            for (ll j = i; j < N; j += i) {
                if (grundy[j] == -1) grundy[j] = cnt;
            }
        }
        if (grundy[i] == -1) {
            cnt++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    ll t;
    cin >> t;
    while (t--) {
        
    }

    return 0;
}
