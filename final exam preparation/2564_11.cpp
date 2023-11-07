/*
6
0 2 10
0 4 15
0 5 20
1 4 5
1 5 30
2 3 10
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
vector<ii> edge[1005], path;
bool vst[1005];
int V, u, v, w, ps, mx, sum;
bool dfs(int u, int p)
{
    if (vst[u])
    {
        ps = path.size();
        // for (int i = 0; i < ps; ++i)
        //     printf("%d %d\n", path[i].first, path[i].second);
        for (int i = ps - 1; i == ps - 1 || path[i].second != u; --i)
            mx = max(mx, path[i].first);
        return 1;
    }
    vst[u] = true;
    for (int i = 0; i < edge[u].size(); ++i)
    {
        w = edge[u][i].first;
        v = edge[u][i].second;
        if (v != p)
        {
            path.push_back({w, v});
            if (dfs(v, u))
                return 1;
            path.pop_back();
        }
    }
    return 0;
}
int main()
{
    scanf("%d", &V);
    for (int i = 0; i < V; ++i)
    {
        scanf("%d %d %d", &u, &v, &w);
        edge[u].push_back({w, v});
        edge[v].push_back({w, u});
        sum += w;
    }
    path.push_back({0, 0});
    dfs(0, -1);
    printf("%d", sum - mx);
}