// O(n)
#include <bits/stdc++.h>
using namespace std;
int n, a[305], dp[305][7];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    dp[2][0] = 0;
    dp[2][1] = a[0];
    dp[2][2] = a[1];
    dp[2][3] = a[2];
    dp[2][4] = a[0] + a[1];
    dp[2][5] = a[0] + a[2];
    dp[2][6] = a[1] + a[2];
    for (int i = 3; i < n; ++i)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i - 1][2], dp[i - 1][4]);
        dp[i][2] = max(dp[i - 1][3], dp[i - 1][5]);
        dp[i][3] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
        dp[i][4] = dp[i - 1][6];
        dp[i][5] = dp[i - 1][2] + a[i];
        dp[i][6] = dp[i - 1][3] + a[i];
    }
    int ans = dp[n - 1][0];
    for (int i = 1; i < 7; ++i)
        ans = max(ans, dp[n - 1][i]);
    printf("DP Potter: %d\n", ans);
}
/*
11
1 2 3 4 5 6 7 80 9 10 11

6
1 2 3 4 5 6

9
455 -626 -411 632 672 -421 803 -439 -277

16
455 -626 -411 632 672 -421 803 -439 -277 -954 859 356 -467 -696 731 96
*/