// O(n^2)
#include <bits/stdc++.h>
using namespace std;
int n, ans, a[10005], dp[10005][10005];
int f(int cur)
{
    if (cur > n)
        return INT_MIN;
    if (cur == n)
        return 0;
    int mx = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i + cur <= n)
        {
            mx = max(mx, a[i] + f(i + cur));
        }
    }
    return mx;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    ans = f(0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= i)
                dp[i][j] = max(dp[i][j], dp[i][j - i] + a[i]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("Brute force: %d\nDP: %d", ans, dp[n][n]);
}