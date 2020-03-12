#include <bits/stdc++.h>

using namespace std;

int solve(int A)
{
    int ans = 0, i = 1;
    while (A > 0)
    {
        ans += (A % 2) * pow(5, i);
        A /= 2;
        i++;
    }
    return ans;
}

int main()
{
    cout << solve(3);
    return 0;
}
