template<typename T>
class BIT {
public:
    vector<T> bit;
    int n;
    BIT(int n) : n(n) {
        bit.assign(n + 1, 0);
    }
    BIT(const vector<T>& values) : n(values.size()) {
        bit.assign(n + 1, 0);
        for (ll i = 0; i < n; ++i) {
            update(i + 1, values[i]);
        }
    }
    void update(ll idx, T val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
    T prefixSum(ll idx) const {
        T sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

template<typename T>
class RangeUpdateBIT {
public:
    BIT<T> BIT1, BIT2;
    int n;

    RangeUpdateBIT(int n) : n(n), BIT1(n), BIT2(n) {}

    void rangeUpdate(ll l, ll r, T val) {
        BIT1.update(l, val);
        BIT1.update(r + 1, -val);
        BIT2.update(l, val * (l - 1));
        BIT2.update(r + 1, -val * r);
    }

    T pointQuery(ll idx) const {
        return BIT1.prefixSum(idx) * idx - BIT2.prefixSum(idx);
    }

    T rangeQuery(ll l, ll r) const {
        return pointQuery(r) - pointQuery(l - 1);
    }
};