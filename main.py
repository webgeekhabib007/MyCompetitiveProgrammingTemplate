MOD = 1000000007

def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        
        pow2 = [1] * (n * 32 + 1)
        for i in range(1, n * 32 + 1):
            pow2[i] = (pow2[i - 1] * 2) % MOD

        ans = 0
        val_size = 0
        val_x = []
        val_y = []

        for i in range(n):
            x, y = a[i], 0
            while x % 2 == 0:
                x //= 2
                y += 1

            while val_size > 0 and (y > 30 or val_x[val_size - 1] < x * (1 << y)):
                ans = (ans - val_x[val_size - 1] * pow2[val_y[val_size - 1]] % MOD + MOD) % MOD
                ans = (ans + val_x[val_size - 1]) % MOD
                y += val_y[val_size - 1]
                val_size -= 1

            val_x.append(x)
            val_y.append(y)
            val_size += 1
            ans = (ans + val_x[val_size - 1] * pow2[val_y[val_size - 1]]) % MOD
            print(ans, end=' ')
        
        print()

if __name__ == "__main__":
    solve()
