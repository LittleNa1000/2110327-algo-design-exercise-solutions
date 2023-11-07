#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 0, n = 30;
    int mn = 0, k = 4;
    for (; n >= 3; ++ans)
    {
        n = (n - 3) / 2;
    }
    while (k--)
    {
        mn = (mn * 2) + 3;
    }
    printf("dist = %d\nmin = %d", ans, mn);
}