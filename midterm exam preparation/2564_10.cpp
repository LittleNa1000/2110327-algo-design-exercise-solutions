// O(n) Solution by Potter
#include <bits/stdc++.h>
using namespace std;
int cnt, sum;
int main()
{
    string T = "))()()((";
    cnt = 0;
    sum = 0;
    for (int i = 0; i < T.length(); ++i)
    {
        if (T[i] == '(')
            ++cnt;
        else
        {
            --cnt;
            if (cnt < 0)
                sum -= cnt;
        }
    }
    printf("%d\n", sum);
}