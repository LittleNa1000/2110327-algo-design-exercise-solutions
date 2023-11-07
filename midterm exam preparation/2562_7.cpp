#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {0, 1, 2, 2, 2};
    int n = sizeof(a) / sizeof(int);
    printf("%d", lower_bound(a, a + n, 2) - lower_bound(a, a + n, 1));
}