// bool b
#include <bits/stdc++.h>
using namespace std;
int V, E, u, v, w, k[8], ans[8], o;
vector<pair<int, int>> edge[25];
bool vst[25];
void found(int s)
{
    for (int i = 0; i < 8; ++i)
        if (k[i] == s)
            ans[i] = 1;
}
int mx()
{
    int x = -1;
    for (int i = 0; i < 8; ++i)
        if (!ans[i] && x < k[i])
            x = k[i];
    return x;
}
void dfs(int u, int s)
{
    found(s);
    int x = mx();
    if (s > x || x == -1)
        return;

    for (int i = 0; i < edge[u].size(); ++i)
    {
        int w = edge[u][i].first, v = edge[u][i].second;
        if (s + w > x)
            return;
        if (!vst[v])
        {
            vst[v] = 1;
            printf("%d %d->%d %d\n", o, u, v, s);
            dfs(v, s + w);
            vst[v] = 0;
        }
    }
}
int main()
{
    scanf("%d %d", &V, &E);
    for (int i = 0; i < 8; ++i)
        scanf("%d", &k[i]);
    for (int i = 0; i < E; ++i)
    {
        scanf("%d %d %d", &u, &v, &w);
        edge[u].push_back({w, v});
        edge[v].push_back({w, u});
    }
    for (int i = 0; i < V; ++i)
    {
        sort(edge[i].begin(), edge[i].end());
    }
    for (int i = 0; i < V; ++i)
    {
        o = i;
        vst[i] = 1;
        dfs(i, 0);
        vst[i] = 0;
    }
    for (int i = 0; i < 8; ++i)
        if (ans[i])
            printf("YES\n");
        else
            printf("NO\n");
}