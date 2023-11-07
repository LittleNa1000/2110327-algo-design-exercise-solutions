#include <bits/stdc++.h>
using namespace std;
int g[105], gc[105], n;
void f(int idx, int l, int r)
{
    if (l >= r)
        return;
    if (idx == 0)
    {
        // printf("LAST %d %d %d\n", idx, l, r);
        if (l == n)
            printf("g");
        else
            printf("a");
        return;
    }
    int m1 = l + g[idx - 1], m2 = m1 + 3 + idx;
    if (l <= n && n <= m1 - 1)
    {
        // printf("L\n");
        f(idx - 1, l, m1);
    }
    else if (m1 <= n && n <= m2 - 1)
    {
        // printf("M %d %d %d %d %d\n", idx, l, m1, m2, r);
        if (m1 == n)
            printf("g");
        else
            printf("a");
    }
    else if (m2 <= n && n <= r - 1)
    {
        // printf("R\n");
        f(idx - 1, m2, r);
    }
}
int main()
{
    g[0] = 3;
    gc[0] = 1;
    for (int i = 1; i < 28; ++i)
    {
        g[i] = g[i - 1] + g[i - 1] + 1 + i + 2;
        // gc[i] = gc[i - 1] * 2 + 1;
        // printf("%d %lld %lld\n", i, g[i], gc[i]);
    }
    scanf("%d", &n);
    --n;
    f(27, 0, g[27] + 1);
}