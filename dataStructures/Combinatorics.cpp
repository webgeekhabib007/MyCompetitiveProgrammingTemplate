class Combinatorics {
private:
    ll MOD;
    ll MAX_N;
    vector<ll> fact, inv_fact;

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
        inv_fact[MAX_N] = power(fact[MAX_N], MOD - 2, MOD);
        for (ll i = MAX_N - 1; i >= 0; --i) {
            inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
        }
    }

public:
    Combinatorics(ll max_n, ll mod) : MAX_N(max_n), MOD(mod), fact(max_n + 1), inv_fact(max_n + 1) {
        precompute_factorials();
    }
    ll nCr(ll n, ll r) {
        if (r > n || r < 0) return 0;
        return (fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD) % MOD;
    }
    ll nPr(ll n, ll r) {
        if (r > n || r < 0) return 0;
        return (fact[n] * inv_fact[n - r] % MOD) % MOD;
    }
};