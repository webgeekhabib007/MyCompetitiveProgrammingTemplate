#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

struct Query {
    ll L, R, idx;
};
const ll blockSize = 555;
bool compare(Query a, Query b) {
    ll block_a = a.L / blockSize;
    ll block_b = b.L / blockSize;
    if (block_a != block_b)
        return block_a < block_b;
    return a.R < b.R;
}

class MoAlgorithm {
private:
    vector<ll> arr;
    vector<Query> queries;
    vector<ll> answer;
    ll distinctCount;
    vector<ll> freq;
    ll sqrtN;

public:
    MoAlgorithm(const vector<ll>& input, const vector<Query>& q) : arr(input), queries(q), distinctCount(0) {
        int n = arr.size();
        sqrtN = sqrt(n);
        answer.resize(queries.size());
        freq.resize(*max_element(arr.begin(), arr.end()) + 5, 0);
    }

    void add(ll idx) {
        freq[arr[idx]]++;
        if (freq[arr[idx]] == 1) distinctCount++;
    }

    void remove(ll idx) {
        if (freq[arr[idx]] == 1) distinctCount--;
        freq[arr[idx]]--;
    }

    vector<ll> processQueries() {
        sort(queries.begin(), queries.end(), compare);
        ll currentL = 0, currentR = -1;

        for (auto& q : queries) {
            ll L = q.L, R = q.R;
            while (currentR < R) add(++currentR);
            while (currentR > R) remove(currentR--);
            while (currentL < L) remove(currentL++);
            while (currentL > L) add(--currentL);
            answer[q.idx] = distinctCount;
        }

        return answer;
    }
};

int main() {
    vector<ll> arr = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    vector<Query> queries = { {0, 4, 0}, {1, 3, 1}, {2, 4, 2} };

    MoAlgorithm mo(arr, queries);
    vector<ll> result = mo.processQueries();

    for (ll i = 0; i < result.size(); ++i) {
        cout << "Query " << i + 1 << ": " << result[i] << " distinct elements\n";
    }

    return 0;
}
