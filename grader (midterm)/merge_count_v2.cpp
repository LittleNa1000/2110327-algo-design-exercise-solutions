#include <bits/stdc++.h>
using namespace std;
int n, k, cnt = 1;
vector<int> v;
void ms(int l, int r)
{
    if (l >= r)
        return;

    if (r - l == 1 || cnt + 2 > k)
    {
        return;
    }
    cnt += 2;
    // for (int i = 0; i < n; ++i)
    //     printf("%d ", v[i]);
    // printf("\n%d\n", cnt);
    // printf("%d %d\n", l, r);
    int m = ((l + r + 1) / 2), m2 = ((l + r + 0) / 2);
    // printf("%d %d %d\n", l, m, r);
    vector<int> t;
    int i = l, j = m, k = l;
    while (j < r)
    {
        t.push_back(v[j++]);
    }
    while (i < m)
    {
        t.push_back(v[i++]);
    }

    for (int k = 0; k < t.size(); ++k)
        v[k + l] = t[k];
    ms(l, m2);
    ms(m2, r);

    return;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        v.push_back(i + 1);
    }
    ms(0, n);
    if (cnt != k)
    {
        printf("-1");
        return 0;
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", v[i]);
    // printf("\n%d", cnt);
}