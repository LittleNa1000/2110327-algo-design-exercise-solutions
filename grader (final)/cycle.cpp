#include <bits/stdc++.h>
using namespace std;
int Q, V, E, u, v;
bool b;
bool vst[1005][105];
vector<int> edge[1005][105];
void dfs(int u, int p)
{
    if (vst[u][Q])
    {
        b = 1;
        return;
    }
    vst[u][Q] = 1;
    for (int i = 0; i < edge[u][Q].size(); ++i)
    {
        if (edge[u][Q][i] != p)
        {
            dfs(edge[u][Q][i], u);
        }
    }
}
int main()
{
    scanf("%d", &Q);
    while (Q--)
    {
        b = 0;
        scanf("%d%d", &V, &E);
        for (int i = 0; i < E; ++i)
        {
            scanf("%d %d", &u, &v);
            edge[u][Q].push_back(v);
            edge[v][Q].push_back(u);
        }
        for (int i = 0; i < V; ++i)
        {
            if (!vst[i][Q])
                dfs(i, -1);
        }

        if (b)
            printf("YES\n");
        else
            printf("NO\n");
    }
}