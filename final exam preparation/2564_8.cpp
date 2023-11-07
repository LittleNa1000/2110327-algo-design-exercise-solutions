#include <bits/stdc++.h>
using namespace std;
int open(int r, int c)
{
}
bool chk(int n, vector<pair<int, int>> mines)
{
    if (mines.size() != n)
        return false;
    for (int i = 0; i < n; ++i)
        if (open(mines[i].first, mines[i].second) != -1)
            return false;
    return true;
}
int main() {}