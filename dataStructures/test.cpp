#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string ryad, eryad;
        cin >> ryad >> eryad;
        vector<vector<long long>> dp(2, vector<long long>(n + 1, 0));
        dp[0][0] = dp[1][0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (ryad[i - 1] == '0' && eryad[i - 1] == '0')
            {
                dp[0][i] = dp[0][i - 1];
                dp[1][i] = dp[1][i - 1];
            }
            else if (ryad[i - 1] == '1' && eryad[i - 1] == '0')
            {
                dp[0][i] = dp[0][i - 1] + 1;
                dp[1][i] = dp[1][i - 1];
            }
            else if (ryad[i - 1] == '0' && eryad[i - 1] == '1')
            {
                dp[0][i] = dp[0][i - 1];
                dp[1][i] = dp[1][i - 1] + 1;
            }
            else
            {
                dp[0][i] = dp[0][i - 1] + 1;
                dp[1][i] = dp[1][i - 1] + 1;
            }
        }

        if (dp[0][n] < dp[1][n])
            cout << dp[0][n] << "\n";
        else if (dp[0][n] > dp[1][n])
            cout << dp[1][n] << "\n";
        else
            cout << dp[0][n] << "\n" << 2 << "\n";

    }

    return 0;
}