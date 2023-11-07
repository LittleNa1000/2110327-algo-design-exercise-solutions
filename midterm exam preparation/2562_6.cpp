#include <bits/stdc++.h>
using namespace std;
const int n = 2;
int b[6][n + 1], a[6][n + 1] = {{0, 0, 0}, {0, 1, 10}, {0, 3, 30}, {0, 4, -40}, {0, 60, -60}, {0, -2, -20}};
int main()
{
    for (int c = 1; c <= n; ++c)
    {
        for (int r = 1; r <= 5; ++r)
        {
            b[r][c] = a[r][c];
            if (c > 1 && r == 1)
                b[r][c] += max(b[r][c - 1], b[r + 1][c - 1]);
            else if (c > 1 && 1 < r && r < 5)
                b[r][c] += max(b[r][c - 1], max(b[r + 1][c - 1], b[r - 1][c - 1]));
            else if (c > 1 && r == 5)
                b[r][c] += max(b[r][c - 1], b[r - 1][c - 1]);
        }
    }
    for (int c = 1; c <= n; ++c)
    {
        for (int r = 1; r <= 5; ++r)
        {
            printf("%d ", b[r][c]);
        }
        printf("\n");
    }
}