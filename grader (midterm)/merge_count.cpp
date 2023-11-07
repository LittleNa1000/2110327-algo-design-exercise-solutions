#include <bits/stdc++.h>
using namespace std;
int n, k, cnt;
vector<int> v;
void ms(int l, int r)
{
    if (l >= r)
        return;
    ++cnt;
    bool b = true;
    for (int k = l; k < r - 1; ++k)
    {
        if (v[k] > v[k + 1])
            b = false;
    }
    if (b)
        return;

    for (int i = 0; i < n; ++i)
        printf("%d ", v[i]);
    printf("\n%d\n", cnt);
    printf("%d %d\n", l, r);
    if (r - l == 1)
    {
        return;
    }
    int m = (l + r) / 2;
    // printf("%d %d %d\n", l, m, r);

    ms(l, m);
    ms(m, r);
    vector<int> t;
    int i = l, j = m;
    while (i < m && j < r)
    {
        if (v[i] < v[j])
            t.push_back(v[i++]);
        else
            t.push_back(v[j++]);
    }
    while (i < m)
    {
        t.push_back(v[i++]);
    }
    while (j < r)
    {
        t.push_back(v[j++]);
    }
    for (int k = 0; k < t.size(); ++k)
        v[k + l] = t[k];
    return;
}
int main()
{
    scanf("%d%d", &n, &k);
    int tem;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tem);
        v.push_back(tem);
    }
    ms(0, n);
    for (int i = 0; i < n; ++i)
        printf("%d ", v[i]);
    printf("\n%d", cnt);
}