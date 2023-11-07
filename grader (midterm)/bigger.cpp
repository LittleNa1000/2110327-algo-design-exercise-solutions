#include <bits/stdc++.h>
using namespace std;
int n, x, dp[10005];
int main()
{
    scanf("%d", &n);
    for (int i = 3; i < n + 3; ++i)
    {
        scanf("%d", &x);
        dp[i] = max(dp[i - 1], max(dp[i - 2], dp[i - 3] + x));
    }
    printf("%d", dp[n + 2]);
}