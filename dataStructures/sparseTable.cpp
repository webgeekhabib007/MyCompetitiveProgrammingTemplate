#include <vector>
#include <math.h>

using namespace std;


class SparseTableMin {
    public:
        vector<vector<int> > st;

        SparseTableMin(vector<int>& nums){
            int n = nums.size();
            int k = log2(n)+1;

            st.assign(n,vector<int>(k));

            for(int i=0;i<n;i++){
                st[i][0] = nums[i];
            }

            for(int j = 1;j<=k;j++){
                for(int i=0;i+(1<<j)<= n;i++){
                    st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
                }
            }
        }

        int query(int left,int right){
            int j = log2(right-left+1);
            return min(st[left][j],st[right - (1<<j) + 1][j]);
        }
};


class SparseTableSum {
public:
    vector<vector<int>> st;

    SparseTableSum(vector<int>& nums) {
        int n = nums.size();
        int k = log2(n) + 1;

        st.assign(n, vector<int>(k));

        for (int i = 0; i < n; i++) {
            st[i][0] = nums[i];
        }

        for (int j = 1; j < k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    // time complexity- O(log(n))
    int query(int left, int right) {
        int sum = 0;
        for (int j = log2(right - left + 1); j >= 0; j--) {
            if ((1 << j) <= right - left + 1) {
                sum += st[left][j];
                left += 1 << j;
            }
        }
        return sum;
    }
};


class SparseTableXor {
public:
    vector<vector<int>> st;

    SparseTableXor(vector<int>& nums) {
        int n = nums.size();
        int k = log2(n) + 1;

        st.assign(n, vector<int>(k));

        for (int i = 0; i < n; i++) {
            st[i][0] = nums[i];
        }

        for (int j = 1; j < k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = st[i][j - 1] ^ st[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int query(int left, int right) {
        int result = 0;
        for (int j = log2(right - left + 1); j >= 0; j--) {
            if ((1 << j) <= right - left + 1) {
                result ^= st[left][j];
                left += 1 << j;
            }
        }
        return result;
    }
};