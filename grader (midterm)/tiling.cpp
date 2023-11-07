#include <bits/stdc++.h>
using namespace std;
int l, x, y;
bool in(int x1, int y1, int x2, int y2, int x, int y)
{
    return (bool)(x1 <= x && x <= x2 && y1 <= y && y <= y2);
}
void f(int len, int x1, int y1, int x2, int y2, int x, int y)
{
    if (len == 1)
    {
        // printf("(%d %d)", x1, y1);
        return;
    }
    int xm = (x1 + x2) / 2, ym = (y1 + y2) / 2;
    if (in(x1, y1, xm, ym, x, y))
    {
        // 2
        printf("0 ");
        printf("%d %d\n", xm, ym);
        // f(len / 2, x1, y1, xm, ym, xm, ym);
        f(len / 2, xm + 1, y1, x2, ym, xm + 1, ym);
        f(len / 2, x1, ym + 1, xm, y2, xm, ym + 1);
        f(len / 2, xm + 1, ym + 1, x2, y2, xm + 1, ym + 1);
        return f(len / 2, x1, y1, xm, ym, x, y);
    }
    if (in(xm + 1, y1, x2, ym, x, y))
    {
        // 1
        printf("1 ");
        printf("%d %d\n", xm, ym);
        f(len / 2, x1, y1, xm, ym, xm, ym);
        // f(len / 2, xm + 1, y1, x2, ym, xm+1, ym);
        f(len / 2, x1, ym + 1, xm, y2, xm, ym + 1);
        f(len / 2, xm + 1, ym + 1, x2, y2, xm + 1, ym + 1);
        return f(len / 2, xm + 1, y1, x2, ym, x, y);
    }
    if (in(x1, ym + 1, xm, y2, x, y))
    {
        // 3
        printf("2 ");
        printf("%d %d\n", xm, ym);
        f(len / 2, x1, y1, xm, ym, xm, ym);
        f(len / 2, xm + 1, y1, x2, ym, xm + 1, ym);
        // f(len / 2, x1, ym + 1, xm, y2, xm, ym+1);
        f(len / 2, xm + 1, ym + 1, x2, y2, xm + 1, ym + 1);
        return f(len / 2, x1, ym + 1, xm, y2, x, y);
    }
    if (in(xm + 1, ym + 1, x2, y2, x, y))
    {
        // 4
        printf("3 ");
        printf("%d %d\n", xm, ym);
        f(len / 2, x1, y1, xm, ym, xm, ym);
        f(len / 2, xm + 1, y1, x2, ym, xm + 1, ym);
        f(len / 2, x1, ym + 1, xm, y2, xm, ym + 1);
        // f(len / 2, xm + 1, ym + 1, x2, y2, xm+1, ym+1);
        return f(len / 2, xm + 1, ym + 1, x2, y2, x, y);
    }
}
int main()
{
    scanf("%d %d %d", &l, &x, &y);
    printf("%d\n", (l * l - 1) / 3);
    f(l, 0, 0, l - 1, l - 1, x, y);
}