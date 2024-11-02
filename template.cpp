#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int cmp(int x, int y, int z) {
    if (z > 30) return 1;
    return x < y * (1LL << z);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int *a = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        long long *pow2 = (long long *)malloc((n * 32 + 1) * sizeof(long long));
        pow2[0] = 1;
        for (int i = 1; i <= n * 32; i++) {
            pow2[i] = pow2[i - 1] * 2 % MOD;
        }

        long long ans = 0;
        int val_size = 0;
        int *val_x = (int *)malloc(n * sizeof(int));
        int *val_y = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            int x = a[i], y = 0;
            while (x % 2 == 0) {
                x /= 2;
                y++;
            }

            while (val_size > 0 && cmp(val_x[val_size - 1], x, y)) {
                ans = (ans - val_x[val_size - 1] * pow2[val_y[val_size - 1]] % MOD + MOD) % MOD;
                ans = (ans + val_x[val_size - 1]) % MOD;
                y += val_y[val_size - 1];
                val_size--;
            }

            val_x[val_size] = x;
            val_y[val_size] = y;
            val_size++;
            ans = (ans + val_x[val_size - 1] * pow2[val_y[val_size - 1]]) % MOD;
            printf("%lld ", ans);
        }
        printf("\n");

        free(a);
        free(pow2);
        free(val_x);
        free(val_y);
    }
    return 0;
}
