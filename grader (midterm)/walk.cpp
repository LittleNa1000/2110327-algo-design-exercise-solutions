#include <bits/stdc++.h>
using namespace std;
int n, m, x, dp[505][505];
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &x);
            if (i == 1 || j == 1)
                dp[i][j] = x + max(dp[i - 1][j], max(dp[i][j - 1], 0));
            else
                dp[i][j] = x + max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1] + x));
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d", dp[n][m]);
}