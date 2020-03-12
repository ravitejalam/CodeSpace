#include <bits/stdc++.h>

using namespace std;

int solve(int A, int B)
{
    return 2*(B/3) + B%3 - 2*((A-1)/3) - (A-1)%3;
}

int main()
{
    cout << solve(30, 36);
    return 0;
}
