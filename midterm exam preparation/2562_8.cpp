#include <bits/stdc++.h>
using namespace std;
int n;
double dp[105] = {2, 3};
double f(int n)
{
    if (dp[n] != 0)
        return dp[n];
    return dp[n] = f(n - 1) + f(n - 2);
}
int main()
{
    for (int n = 1; n <= 100; ++n)
    {
        printf("%.0lf\n", f(n));
    }
}