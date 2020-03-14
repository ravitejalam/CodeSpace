#include <bits/stdc++.h>

using namespace std;

int solve(int A, int B, int C)
{
    int Com[B + 1];
    memset(Com, 0, sizeof(Com));

    Com[0] = 1;
    for (int i = 1; i <= A; i++)
    {
        for (int j = min(i, B); j > 0; j--)
            Com[j] = (Com[j] + Com[j - 1]) % C;
    }
    return Com[B];
}

int main()
{
    cout << solve(38, 5, 81);
    return 0;
}
