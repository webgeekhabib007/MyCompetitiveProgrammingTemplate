#include <vector>
#include <climits>

class SegmentTreeMin {
private:
    std::vector<int> tree;
    std::vector<int> lazy;
    int n;

    void buildTree(std::vector<int>& arr, int start, int end, int treeNode) {
        if (start == end) {
            tree[treeNode] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        buildTree(arr, start, mid, 2 * treeNode);
        buildTree(arr, mid + 1, end, 2 * treeNode + 1);
        tree[treeNode] = std::min(tree[2 * treeNode], tree[2 * treeNode + 1]);
    }

    void updateTree(int left, int right, int start, int end, int treeNode, int value) {
        if (lazy[treeNode] != 0) {
            tree[treeNode] += lazy[treeNode];
            if (start != end) {
                lazy[2 * treeNode] += lazy[treeNode];
                lazy[2 * treeNode + 1] += lazy[treeNode];
            }
            lazy[treeNode] = 0;
        }
        // No overlap
        if (start > right || end < left) {
            return;
        }
        // Complete overlap
        if (start >= left && end <= right) {
            tree[treeNode] += value;
            if (start != end) {
                lazy[2 * treeNode] += value;
                lazy[2 * treeNode + 1] += value;
            }
            return;
        }
        // Partial overlap
        int mid = (start + end) / 2;
        updateTree(left, right, start, mid, 2 * treeNode, value);
        updateTree(left, right, mid + 1, end, 2 * treeNode + 1, value);
        tree[treeNode] = std::min(tree[2 * treeNode], tree[2 * treeNode + 1]);
    }

    int queryTree(int left, int right, int start, int end, int treeNode) {
        if (lazy[treeNode] != 0) {
            tree[treeNode] += lazy[treeNode];
            if (start != end) {
                lazy[2 * treeNode] += lazy[treeNode];
                lazy[2 * treeNode + 1] += lazy[treeNode];
            }
            lazy[treeNode] = 0;
        }
        // No overlap
        if (start > right || end < left) {
            return INT_MAX;
        }
        // Complete overlap
        if (start >= left && end <= right) {
            return tree[treeNode];
        }
        // Partial overlap
        int mid = (start + end) / 2;
        int ans1 = queryTree(left, right, start, mid, 2 * treeNode);
        int ans2 = queryTree(left, right, mid + 1, end, 2 * treeNode + 1);
        return std::min(ans1, ans2);
    }

public:
    SegmentTreeMin(std::vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        buildTree(arr, 0, n - 1, 1);
    }

    void update(int left, int right, int value) {
        updateTree(left, right, 0, n - 1, 1, value);
    }

    int query(int left, int right) {
        return queryTree(left, right, 0, n - 1, 1);
    }
};