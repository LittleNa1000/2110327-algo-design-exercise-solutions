// O(logN)
#include <bits/stdc++.h>
using namespace std;
int x;
void double_x()
{
    x *= 2;
}
void increase_x()
{
    ++x;
}
void f(int n)
{
    int x = 1;
    stack<bool> s;
    bool b;
    while (n > 1)
    {
        if (n % 2)
        {
            s.push(1);
            --n;
        }
        s.push(0);
        n /= 2;
    }
    while (!s.empty())
    {
        b = s.top();
        s.pop();
        if (b)
            increase_x();
        else
            double_x();
    }
}
int main()
{
    for (int n = 1; n <= 200; ++n)
    {
        x = 1;
        f(n);
        printf("%d\n", x);
    }
}