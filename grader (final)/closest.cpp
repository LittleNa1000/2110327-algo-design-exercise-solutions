#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans = INT_MAX - 1000000, a[1005], q[1005];
bool b;
int sum(int l, int r)
{
    if (!l)
        return q[r];
    return q[r] - q[l - 1];
}
void f(int c, int i, int s)
{

    if (c == m)
    {
        // printf("c=%d i=%d s=%d\n", c, i, s);
        ans = min(ans, abs(k - s));
        if (ans == 0)
            b = 1;
        return;
    }
    if (s + sum(i, i + (m - c)) >= ans + k)
        return;
    for (int j = i; j < n; ++j)
    {
        if (s + a[j] >= ans + k)
            return;
        f(c + 1, j + 1, s + a[j]);
        if (b)
            return;
    }
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        if (!i)
            q[i] = a[i];
        q[i] = a[i] + q[i - 1];
    }
    sort(a, a + n);
    f(0, 0, 0);
    printf("%d", ans);
}