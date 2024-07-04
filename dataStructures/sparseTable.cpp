template<typename T>
class SparseTable {
private:
    vector<vector<T>> st;
    int n, k;

public:
    SparseTable(const vector<T>& arr) {
        n = arr.size();
        k = log2(n) + 1;
        st.assign(n, vector<T>(k));

        for (int i = 0; i < n; ++i)
            st[i][0] = arr[i];

        for (int j = 1; j < k; ++j)
            for (int i = 0; i + (1 << j) <= n; ++i)
                st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];

    }

    T query(int L, int R) {
        T sum = 0;
        while (L <= R) {
            int j = log2(R - L + 1);
            sum += st[L][j];
            L += (1 << j);
        }
        return sum;
    }
};