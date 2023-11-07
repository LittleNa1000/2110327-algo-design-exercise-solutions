// O(log3(n))
// Call w() 1+2*log3(n) times
#include <bits/stdc++.h>
using namespace std;
int n = 729, x = -1, k;
int w(int l, int r)
{
    if (l <= k && k <= r)
        return 2 * (r - l + 1) + x;
    return 2 * (r - l + 1);
}
int f()
{
    int l = 1, r = n;
    int l2 = l + ((r - l + 1) / 3), r1 = l2 - 1, l3 = l + (2 * (r - l + 1) / 3), r2 = l3 - 1;
    int w1 = w(l, r1), w2 = w(l2, r2), w3 = w(l3, r);
    bool isLess, st = 1;
    if (w1 == w2)
    {
        isLess = w2 > w3 ? 1 : 0;
    }
    else if (w2 == w3)
    {
        isLess = w2 > w1 ? 1 : 0;
    }
    else
    {
        isLess = w3 > w2 ? 1 : 0;
    }
    while (l < r)
    {
        l2 = l + ((r - l + 1) / 3);
        r1 = l2 - 1;
        l3 = l + (2 * (r - l + 1) / 3);
        r2 = l3 - 1;
        if (!st)
        {
            w1 = w(l, r1);
            w2 = w(l2, r2);
        }
        st = 0;
        // printf("%d %d %d %d %d %d\n", l, r1, l2, r2, l3, r);
        if (w1 == w2)
        {
            l = l3;
        }
        else if ((w1 < w2 && isLess) || (w1 > w2 && !isLess))
        {
            r = r1;
        }
        else
        {
            l = l2;
            r = r2;
        }
        if (l == r)
        {
            return l;
        }
    }
}
int main()
{
    for (int i = n; i > 0; --i)
    {
        k = i;
        int res = f();
        if (i != res)
            printf("Wrong\n");
        printf("%d\n", res);
    }
}