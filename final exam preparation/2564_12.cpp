#include <bits/stdc++.h>
using namespace std;
int n, L, ans, s, cur;
vector<int> a, l, sol;
bool chk[105];
void f(int w, int b, int sum)
{
    if (sum == 0 && b < ans)
    {
        for (int i = 0; i < a.size(); ++i)
            printf("%d ", a[i]);
        printf(" = %d box\n", b);
        sol = a;
        ans = b;
        return;
    }
    if (b + ceil((double)(sum - L + w) / (double)L) >= ans)
        return;
    // w=30 L=70 {10,30,35,40,50,70} choose up to 40
    printf("%d %d %d\n", w, b, sum);
    bool m = false;
    for (int i = 0; i < n; ++i)
    {
        if (m && w + l[i] > L)
            return;
        if (chk[i])
            continue;
        chk[i] = 1;
        a.push_back(l[i]);
        if (w + l[i] <= L)
            m = true;
        if (w + l[i] > L)
            f(l[i], b + 1, sum - l[i]);
        else
            f(w + l[i], b, sum - l[i]);
        chk[i] = 0;
        a.pop_back();
    }
}
int main()
{
    srand(time(0));
    n = 18;
    ans = n;
    for (int i = 0; i < n; ++i)
        l.push_back(rand() / 100);
    // l.push_back(2);
    for (int i = 0; i < n; ++i)
        s += l[i];
    sort(l.begin(), l.end());
    // L = l[n - 1] + rand() / 100;
    L = max(l[n - 1], s / 8);
    f(0, 1, s);
    for (int i = 0; i < n; cur += sol[i], ++i)
    {
        if (cur + sol[i] > L)
        {
            printf("(%d) | ", cur);
            cur = 0;
        }
        printf("%d ", sol[i]);
    }
    printf("(%d)\nSum=%d L=%d ans=%d", cur, s, L, ans);
}