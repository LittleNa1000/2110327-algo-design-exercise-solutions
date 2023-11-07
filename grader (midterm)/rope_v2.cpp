#include <bits/stdc++.h>
using namespace std;
int x, a, b, c, ans, n;
int main()
{
    scanf("%d %d %d %d", &x, &a, &b, &c);
    for (int i = 0; i <= 4000; ++i)
    {
        for (int j = 0; j <= 4000; ++j)
        {
            n = x - (i * a) - (j * b);
            if (n >= 0 && n % c == 0)
            {
                // printf("%d %d\n", i, j);
                ans = max(ans, i + j + n / c);
            }
        }
    }
    printf("%d", ans);
}