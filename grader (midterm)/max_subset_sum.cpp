#include <bits/stdc++.h>
using namespace std;
int n, tem;
vector<int> v;
int f(int l, int r)
{
    if (l >= r)
        return INT_MIN;
    if (r - l == 1)
        return v[l];
    // printf("(%d %d)\n", l, r);
    int ml = INT_MIN, mr = INT_MIN, sl = 0, sr = 0, m = (l + r) / 2;
    for (int i = m - 1; i >= l; --i)
    {
        sl += v[i];
        ml = max(ml, sl);
    }
    for (int i = m; i < r; ++i)
    {
        sr += v[i];
        mr = max(mr, sr);
    }
    int ans = max(ml + mr, max(f(l, m), f(m, r)));
    // printf("(%d %d) %d\n", l, r, ans);
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tem);
        v.push_back(tem);
    }
    printf("%d", f(0, n));
}