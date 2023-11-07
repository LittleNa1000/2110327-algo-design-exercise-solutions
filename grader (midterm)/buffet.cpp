#include <bits/stdc++.h>
using namespace std;
int n, K, m, tem, l, s, ans, qs[200005], L;
int range(int l, int r)
{
    return qs[r] - qs[l - 1];
}
void f(int l, int r, int s)
{
    if (l > r)
        return;
    int m = (l + r) / 2, sum = range(L, m);
    // printf("%d %d %d %d\n", l, m, r, sum);
    if (sum >= s)
    {
        ans = min(ans, m);
        if (l != r)
            f(l, m, s);
    }
    else
    {
        if (l != r)
            f(m + 1, r, s);
    }
}
int main()
{
    scanf("%d %d %d", &n, &K, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &tem);
        tem -= m;
        qs[i] = qs[i - 1] + tem;
    }
    for (int i = 0; i < K; ++i)
    {
        scanf("%d %d", &L, &s);
        ans = INT_MAX;
        f(L, n, s);
        printf("%d\n", ans);
    }
}