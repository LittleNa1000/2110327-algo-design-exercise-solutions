// O(2^n)
#include <bits/stdc++.h>
using namespace std;
int n, a[1005];
bool b[1005];
void pa()
{
    printf("a: ");
    for (int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    printf(" -> ");
    b[n] = !b[n];
    for (int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    printf("\n");
}
void pb()
{
    printf("b: ");
    for (int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    printf(" -> ");
    for (int i = n; i >= 1; --i)
        if (b[i])
        {
            b[i - 1] = !b[i - 1];
            break;
        }
    for (int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    printf("\n");
}
int f(int idx, int n);
int g(int idx, int n)
{
    if (idx == n)
        return 0;
    if (idx + 1 == n)
    {
        pa();
        return 1;
    }
    int c = 1;
    c += g(idx + 1, n);
    c += f(idx + 2, n);
    pb();
    c += g(idx + 2, n);
    return c;
}
int f(int idx, int n)
{
    if (idx == n)
        return 0;
    if (idx + 1 == n)
    {
        pa();
        return 1;
    }
    int c = 1;
    c += f(idx + 2, n);
    pb();
    c += g(idx + 2, n);
    c += f(idx + 1, n);
    a[n] = c;
    return c;
}
int main()
{
    for (n = 1; n <= 7; ++n)
    {
        for (int i = 1; i <= n; ++i)
            b[i] = 1;
        int c = f(0, n);
        for (int i = 1; i <= n; ++i)
            printf("%d ", b[i]);
        printf("\nCount: %d\n", c);
    }
    for (n = 1; n <= 7; ++n)
    {
        printf("%d ", a[n]);
    }
}