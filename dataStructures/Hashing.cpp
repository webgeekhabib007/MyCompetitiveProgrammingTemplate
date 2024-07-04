class PrimePowerCalculator {
private:
    const ll m1 = 1e9 + 9; 
    const ll m2 = 1e9 + 7; 
    ll p1, p2;             

public:
    PrimePowerCalculator(ll prime1, ll prime2) : p1(prime1), p2(prime2) {}

    void computePowers(vector<ll>& p1_powers, vector<ll>& p2_powers, ll n) {
        p1_powers.resize(n + 1);
        p2_powers.resize(n + 1);

        p1_powers[0] = p2_powers[0] = 1;
        for (ll i = 1; i <= n; ++i) {
            p1_powers[i] = (p1_powers[i - 1] * p1) % m1;
            p2_powers[i] = (p2_powers[i - 1] * p2) % m2;
        }
    }
};

class DoubleHash {
private:
    const ll m1 = 1e9 + 9; 
    const ll m2 = 1e9 + 7; 

    const ll p1, p2;

    vector<ll> hash1_values; 
    vector<ll> hash2_values; 

public:
    DoubleHash(const string& s, const vector<ll>& p1_p, const vector<ll>& p2_p, const ll _p1, const ll _p2)
        : p1(_p1), p2(_p2) {
        ll n = s.size();
        hash1_values.resize(n + 1);
        hash2_values.resize(n + 1);

        hash1_values[0] = hash2_values[0] = 0;
        for (ll i = 1; i <= n; ++i) {
            hash1_values[i] = (hash1_values[i - 1] * p1 + (s[i - 1] - 'a' + 1)) % m1;
            hash2_values[i] = (hash2_values[i - 1] * p2 + (s[i - 1] - 'a' + 1)) % m2;
        }
    }

    // Compute hash of substring s[l...r-1] (0-indexed)
    pair<ll, ll> hashSubstring(ll l, ll r, const vector<ll>& p1_powers, const vector<ll>& p2_powers) {
        l++,r++;
        ll hash1_val = (hash1_values[r] - (hash1_values[l - 1] * p1_powers[r - l + 1]) % m1 + m1) % m1;
        ll hash2_val = (hash2_values[r] - (hash2_values[l - 1] * p2_powers[r - l + 1]) % m2 + m2) % m2;
        return { hash1_val, hash2_val };
    }
};