#include <bits/stdc++.h>
using namespace std;
struct T
{
    int d, i, j, f, f2, f3;
};
bool operator<(const T &a, const T &b)
{
    return a.d > b.d;
}
priority_queue<T> pq;
int dp[10][10][6][6][6], vst[10][10][6][6][6];
int n, m, p, q, nx, nx2, nx3, a[6], ans = INT_MAX;
int op(int x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return 0;
    if (x == 2)
        return 3;
    if (x == 3)
        return 2;
    if (x == 4)
        return 5;
    if (x == 5)
        return 4;
}
void up(int x, int x2, int x3)
{
    nx = x2;
    nx2 = op(x);
    nx3 = x3;
}
void down(int x, int x2, int x3)
{
    nx = op(x2);
    nx2 = x;
    nx3 = x3;
}
void left(int x, int x2, int x3)
{
    nx = x3;
    nx2 = x2;
    nx3 = op(x);
}
void right(int x, int x2, int x3)
{
    nx = op(x3);
    nx2 = x2;
    nx3 = x;
}
int main()
{
    // dp[r][c][ด้านลูกเต๋า]
    scanf("%d%d%d%d", &n, &m, &p, &q);
    for (int i = 0; i < 6; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < 6; ++k)
            {
                for (int k2 = 0; k2 < 6; ++k2)
                    for (int k3 = 0; k3 < 6; ++k3)
                        dp[i][j][k][k2][k3] = INT_MAX;
            }
        }
    }
    dp[0][0][0][4][3] = 0;
    pq.push({0, 0, 0, 0, 4, 3});
    while (!pq.empty())
    {
        int dist = pq.top().d;
        int i = pq.top().i;
        int j = pq.top().j;
        int f = pq.top().f; // face
        int f2 = pq.top().f2;
        int f3 = pq.top().f3;
        pq.pop();
        ++vst[i][j][f][f2][f3];
        if (vst[i][j][f][f2][f3] > 100)
        {
            printf("-1");
            return 0;
        }
        if (i == p && j == q)
        {
            ans = min(ans, dist);
        }
        down(f, f2, f3);
        if (0 <= i + 1 && i + 1 < n && dist + a[nx] < dp[i + 1][j][nx][nx2][nx3])
        {
            dp[i + 1][j][nx][nx2][nx3] = dist + a[nx];
            pq.push({dist + a[nx], i + 1, j, nx, nx2, nx3});
        }
        up(f, f2, f3);
        if (0 <= i - 1 && i - 1 < n && dist + a[nx] < dp[i - 1][j][nx][nx2][nx3])
        {
            dp[i - 1][j][nx][nx2][nx3] = dist + a[nx];
            pq.push({dist + a[nx], i - 1, j, nx, nx2, nx3});
        }
        right(f, f2, f3);
        if (0 <= j + 1 && j + 1 < m && dist + a[nx] < dp[i][j + 1][nx][nx2][nx3])
        {
            dp[i][j + 1][nx][nx2][nx3] = dist + a[nx];
            pq.push({dist + a[nx], i, j + 1, nx, nx2, nx3});
        }
        left(f, f2, f3);
        if (0 <= j - 1 && j - 1 < m && dist + a[nx] < dp[i][j - 1][nx][nx2][nx3])
        {
            dp[i][j - 1][nx][nx2][nx3] = dist + a[nx];
            pq.push({dist + a[nx], i, j - 1, nx, nx2, nx3});
        }
    }
    printf("%d", ans);
}