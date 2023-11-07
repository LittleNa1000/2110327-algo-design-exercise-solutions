#include <bits/stdc++.h>
using namespace std;
int n, L, ans, s, cur;
vector<int> a, l, sol;
bool chk[105];
void f(int w, int b, int sum)
{
    if (sum == 0 && b < ans)
    {
        ans = b;
        return;
    }
    // Lower Bound
    if (b + ceil((double)(sum - L + w) / (double)L) >= ans)
        return;
    bool m = false;
    for (int i = 0; i < n; ++i)
    {
        // Backtrack
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
void getinput()
{
    srand(time(0));
    n = 15;
    for (int i = 0; i < n; ++i)
        l.push_back(rand() / 100);
    sort(l.begin(), l.end());
    for (int i = 0; i < n; ++i)
        s += l[i];
    L = max(l[n - 1], s / 8);
}
int main()
{
    getinput();
    ans = n;
    for (int i = 0, s = 0; i < n; ++i)
        s += l[i];
    f(0, 1, s);
    printf("%d", ans);
}