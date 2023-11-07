// O(n^3)
#include <bits/stdc++.h>
using namespace std;
int n, a[305], dp[305][305], dp2[305][305][305], dp3[305][7];
bool b[305][305], b2[305][305][305];
int f(int idx, int pv1, int pv2)
{
    if (idx == n + 1)
        return 0;
    if (b[pv1][pv2])
    {
        return dp[pv1][pv2];
    }
    int mx = max(0, f(idx + 1, pv1, pv2));
    if (idx - pv2 >= 4 || pv2 == 0)
    {
        int res = a[idx] + f(idx + 1, idx, pv1);
        if (res > mx)
        {
            mx = res;
        }
    }
    dp[pv1][pv2] = mx;
    b[pv1][pv2] = 1;
    return mx;
}
int f2(int idx, int pv1, int pv2)
{
    if (idx == n + 1)
        return 0;
    int mx = max(0, f(idx + 1, pv1, pv2));
    if (idx - pv2 >= 4 || pv2 == 0)
    {
        int res = a[idx] + f(idx + 1, idx, pv1);
        if (res > mx)
        {
            mx = res;
        }
    }
    return mx;
}
int f3(int idx, int pv1, int pv2)
{
    if (idx == n + 1)
        return 0;
    if (b2[idx][pv1][pv2])
    {
        return dp2[idx][pv1][pv2];
    }
    int mx = max(0, f(idx + 1, pv1, pv2));
    if (idx - pv2 >= 4 || pv2 == 0)
    {
        int res = a[idx] + f(idx + 1, idx, pv1);
        if (res > mx)
        {
            mx = res;
        }
    }
    dp2[idx][pv1][pv2] = mx;
    b2[idx][pv1][pv2] = 1;
    return mx;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    dp3[3][0] = 0;
    dp3[3][1] = a[1];
    dp3[3][2] = a[2];
    dp3[3][3] = a[3];
    dp3[3][4] = a[1] + a[2];
    dp3[3][5] = a[1] + a[3];
    dp3[3][6] = a[2] + a[3];
    for (int i = 4; i <= n; ++i)
    {
        dp3[i][0] = max(dp3[i - 1][0], dp3[i - 1][1]);
        dp3[i][1] = max(dp3[i - 1][2], dp3[i - 1][4]);
        dp3[i][2] = max(dp3[i - 1][3], dp3[i - 1][5]);
        dp3[i][3] = max(dp3[i - 1][0], dp3[i - 1][1]) + a[i];
        dp3[i][4] = dp3[i - 1][6];
        dp3[i][5] = dp3[i - 1][2] + a[i];
        dp3[i][6] = dp3[i - 1][3] + a[i];
    }
    int ans = dp3[n - 1][0];
    for (int i = 1; i < 7; ++i)
        ans = max(ans, dp3[n - 1][i]);
    printf("DP 2D (Wrong): %d\nBrute force: %d\nDP 3D: %d\n", f(1, 0, 0), f2(1, 0, 0), f3(1, 0, 0));
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