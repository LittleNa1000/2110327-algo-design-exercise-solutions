/*
0 15 14 13
12 11 10 9
8 7 6 5
4 3 2 1

1 9 2 4
6 13 3 7
10 0 12 8
5 15 14 11

1 2 3 4
5 6 0 8
9 10 7 11
13 14 15 12
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vv;
map<vv, bool> vst;
struct T
{
    vv first;
    int second, rd;
};
priority_queue<T> pq;
int dist(vv a)
{
    int d = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (a[i][j] == 0)
                continue;
            int i2 = a[i][j] == 0 ? 3 : (a[i][j] - 1) / 4;
            int j2 = a[i][j] == 0 ? 3 : (a[i][j] - 1) % 4;
            d += abs(i2 - i) + abs(j2 - j);
            // if (i2 != i || j2 != j)
            //     ++d;
        }
    }
    return d;
}
bool operator<(const T &a, const T &b)
{
    // int d1 = dist(a.first), d2 = dist(b.first);
    // if (a.second + d1 == b.second + d2)
    //     return a.second > b.second;
    return a.second + a.rd > b.second + b.rd;
}
vv a, ans = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}}, g;
int x[] = {0, 1, 0, -1}, y[] = {-1, 0, 1, 0};
int i, j, i2, j2, d;
void f()
{
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 4; ++j)
            if (g[i][j] == 0)
                return;
}
int main()
{
    a.resize(4);
    for (int i = 0; i < 4; ++i)
    {
        a[i].resize(4);
        for (int j = 0; j < 4; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    pq.push({a, 0, dist(a)});
    while (!pq.empty())
    {
        g = pq.top().first;
        d = pq.top().second;
        int c = pq.top().rd;
        pq.pop();
        if (vst[g] == 1)
        {
            continue;
        }
        vst[g] = 1;
        // for (int i = 0; i < 4; ++i)
        // {
        //     for (int j = 0; j < 4; ++j)
        //         printf("%d\t", g[i][j]);
        //     printf("\n");
        // }
        // printf("d=%d dist=%d\n\n", d, c);
        if (c == 0)
        {
            printf("%d", d);
            return 0;
        }
        f();
        for (int k = 0; k < 4; ++k)
        {
            i2 = i + y[k];
            j2 = j + x[k];
            // or best first search
            if (0 <= i2 && i2 < 4 && 0 <= j2 && j2 < 4)
            {
                swap(g[i][j], g[i2][j2]);
                // if (dist(g) <= di)
                int g2 = dist(g);
                pq.push({g, d + 1, g2});
                if (g2 == 0)
                {
                    printf("%d", d + 1);
                    return 0;
                }
                swap(g[i][j], g[i2][j2]);
            }
        }
    }
}