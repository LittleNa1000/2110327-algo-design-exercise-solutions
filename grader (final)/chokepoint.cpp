#include <bits/stdc++.h>
using namespace std;
int V, v, u;
struct T
{
    int v, w, o;
};
vector<T> edge[100005];
int dfs(int u, int par)
{
    int cnt = 1, idx = -1;
    for (int i = 0; i < edge[u].size(); ++i)
    {
        T e = edge[u][i];
        if (e.v != par)
        {
            edge[u][i].o = e.v;
            edge[u][i].w = dfs(e.v, u);
            cnt += edge[u][i].w;
        }
        else
            idx = i;
    }
    if (idx != -1)
    {
        edge[u][idx].o = u;
        edge[u][idx].w = cnt;
    }
    return cnt;
}
int main()
{
    scanf("%d", &V);
    for (int i = 0; i < V - 1; ++i)
    {
        scanf("%d %d", &v, &u);
        edge[u].push_back({v, -1, -1});
        edge[v].push_back({u, -1, -1});
    }
    dfs(0, -1);
    // for (int i = 0; i < V; ++i)
    // {
    //     for (int j = 0; j < edge[i].size(); ++j)
    //     {
    //         T e = edge[i][j];
    //         printf("%d %d %d %d\n", i, e.v, e.w, e.o);
    //     }
    // }
    queue<long long> q;
    long long ans, x, sum;
    for (int i = 0; i < V; ++i)
    {
        // O(2n) can be reduce to O(n)
        ans = 0, sum = 0;
        for (int j = 0; j < edge[i].size(); ++j)
        {
            T e = edge[i][j];
            if (e.o == e.v)
                x = e.w;
            else
                x = V - e.w;
            // printf("p.%lld ", x);
            q.push(x);
            sum += x;
        }
        while (!q.empty())
        {
            // printf("%lld ", q.front());
            sum -= q.front();
            ans += sum * q.front();
            q.pop();
        }
        printf("%lld\n", ans + V - 1);
    }
}