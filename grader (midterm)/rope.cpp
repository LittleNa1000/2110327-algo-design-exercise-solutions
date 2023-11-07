#include <bits/stdc++.h>
using namespace std;
int x, a, b, c, n;
bool dp[4005][4005];
bool f(int y, int cnt)
{
    if (y < 0)
        return 0;
    if (cnt >= 0)
        // printf("%d %d\n", y, cnt);
        if (y == 0)
        {
            // printf("%d\n", cnt);
            dp[y][cnt] = 1;
            return 1;
        }
    if (y < min(a, min(b, c)))
        return 0;
    if (dp[y][cnt])
        return 1;
    bool ans = (bool)((f(y - a, cnt + 1) + f(y - b, cnt + 1) + f(y - c, cnt + 1)) > 0);
    dp[y][cnt] = ans;
    n++;
    return ans;
}
int main()
{
    scanf("%d %d %d %d", &x, &a, &b, &c);
    f(x, 0);
    for (int i = 4004; i >= 0; --i)
    {
        if (dp[0][i])
        {
            printf("%d", i);
            printf("\n%d", n);
            return 0;
        }
    }
}