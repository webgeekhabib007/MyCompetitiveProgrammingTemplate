#include <vector>
#include <cmath>

template<typename T>
class SquareRootDecomposition {
private:
    std::vector<T> arr;
    std::vector<T> block;
    int blockSize;
    int n;

public:
    SquareRootDecomposition(const std::vector<T>& input) {
        n = input.size();
        blockSize = std::sqrt(n);
        arr = input;
        block.resize((n + blockSize - 1) / blockSize);

        for (int i = 0; i < n; ++i) {
            block[i / blockSize] += arr[i];
        }
    }

    void update(int idx, T val) {
        int blockIndex = idx / blockSize;
        block[blockIndex] += (val - arr[idx]);
        arr[idx] = val;
    }

    T query(int left, int right) {
        T sum = 0;
        for(int i=left;i<=right;){
            if(i%blockSize==0 and i+blockSize-1 <= right){
                sum+= block[i/blockSize];
                i+=blockSize;
            }else{
                sum+= arr[i];
                i++;
            }
        }
        return sum;
    }
};

// Example usage
int main() {
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    SquareRootDecomposition<int> sqrtDecomp(input);

    std::cout << "Sum of range [0, 4]: " << sqrtDecomp.query(0, 4) << std::endl; // Output: 15
    sqrtDecomp.update(3, 10);
    std::cout << "Sum of range [0, 4] after update: " << sqrtDecomp.query(0, 4) << std::endl; // Output: 21

    return 0;
}
