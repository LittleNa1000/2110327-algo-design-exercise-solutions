#include <bits/stdc++.h>
using namespace std;
int n, dp[10005] = {1, 2, 4}, dp2[10005] = {0, 0, 2};
int main()
{
    scanf("%d", &n);
    for (int i = 3; i <= n; ++i)
    {
        dp2[i] = dp2[i - 1] + dp[i - 3];
        dp[i] = dp[i - 1] + dp2[i];
        dp2[i] %= 100000007;
        dp[i] %= 100000007;
    }
    printf("%d ", dp[n]);
}