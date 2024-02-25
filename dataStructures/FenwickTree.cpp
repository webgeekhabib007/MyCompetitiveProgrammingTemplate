
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class FenwickTreeSum {
private:
    vector<int> tree;
public:
    FenwickTreeSum(int size) : tree(size + 1, 0) {}

    void update(int idx, int val) {
        while (idx < tree.size()) {
            tree[idx] += val;
            idx += idx & -idx; // Update the next node
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx; // Move to the parent node
        }
        return sum;
    }
};

//fenwick tree for max range query

#include <vector>
#include <climits>

class FenwickTreeMax {
private:
    std::vector<int> tree;
    std::vector<int> maxArray;
    int n;

public:
    FenwickTreeMax(std::vector<int>& arr) {
        n = arr.size();
        tree.assign(n + 1, 0);
        maxArray.assign(n + 1, INT_MIN);

        for (int i = 0; i < n; i++) {
            update(i, arr[i]);
        }
    }

    void update(int idx, int value) {
        while (idx < n) {
            maxArray[idx + 1] = std::max(maxArray[idx + 1], value);
            idx += (idx & -idx);
        }
    }

    int query(int idx) {
        int maxVal = INT_MIN;
        while (idx > 0) {
            maxVal = std::max(maxVal, maxArray[idx]);
            idx -= (idx & -idx);
        }
        return maxVal;
    }
};

// minimum range query
#include <vector>
#include <climits>

class FenwickTreeMin {
private:
    std::vector<int> tree;
    std::vector<int> minArray;
    int n;

public:
    FenwickTreeMin(std::vector<int>& arr) {
        n = arr.size();
        tree.assign(n + 1, INT_MAX);
        minArray.assign(n + 1, INT_MAX);

        for (int i = 0; i < n; i++) {
            update(i, arr[i]);
        }
    }

    void update(int idx, int value) {
        while (idx < n) {
            minArray[idx + 1] = std::min(minArray[idx + 1], value);
            idx += (idx & -idx);
        }
    }

    int query(int idx) {
        int minVal = INT_MAX;
        while (idx > 0) {
            minVal = std::min(minVal, minArray[idx]);
            idx -= (idx & -idx);
        }
        return minVal;
    }
};

int main() {
    
    return 0;
}
