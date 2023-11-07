// O((m-n+1)^(n-1))
#include <bits/stdc++.h>
using namespace std;
int n, m;
void f(int s, vector<int> v)
{
    if (s > m)
        return;
    if (s < m && v.size() + 1 == n)
        v.push_back(m - s);
    if (v.size() == n)
    {
        for (int i = 0; i < n; ++i)
            printf("%d ", v[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i + s <= (m - n + v.size() + 1); ++i)
    {
        v.push_back(i);
        f(s + i, v);
        v.pop_back();
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    f(0, {});
}