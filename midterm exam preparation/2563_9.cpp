// O(k)
#include <bits/stdc++.h>
using namespace std;
int k;
float f(int k)
{
    float a = 1;
    for (int i = 2; i <= 1 << k; ++i)
        a *= i;
    a *= 1 << ((1 << k) - 1);
    return a;
}
int main()
{
    for (k = 1; k <= 7; ++k)
    {
        printf("%.0f\n", f(k));
    }
}