#include <bits/stdc++.h>
using namespace std;
bool a[] = {1, 0, 0, 0, 1, 1, 1, 0, 0};
int x, y, ans, k = 2;
queue<int> t, ct;
int main()
{
    for (int i = 0; i < sizeof(a) / sizeof(bool); ++i)
    {
        if (a[i])
            t.push(i);
        else
            ct.push(i);
    }
    while (!ct.empty())
    {
        x = ct.front();
        ct.pop();
        while (!t.empty())
        {
            y = t.front();
            t.pop();
            if (x - k <= y && y <= x + k)
            {
                ++ans;
                break;
            }
            if (y > x + k)
                break;
        }
    }
    printf("%d", ans);
}