#include <bits/stdc++.h>
using namespace std;
double p, dp[1005][1005];
double c(int i, int j)
{
    if (i == 0)
        return 1;
    if (j == 0)
        return 0;
    if (dp[i][j] == 0)
        dp[i][j] = p * c(i - 1, j) + (1 - p) * c(i, j - 1);
    return dp[i][j];
}
int main()
{
    int n = 3;
    p = 0.9;
    printf("%f", c(n, n));
}