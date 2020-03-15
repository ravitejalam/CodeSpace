#include <bits/stdc++.h>

using namespace std;

int solve(int A)
{
    int X = 0, Y = 0;
    int last0 = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (A & (1 << i))
        {
            break;
        }
        else
        {
            last0 = i;
        }
    }
    for (int i = 0; i < last0; i++)
    {
        if (!(A & (1 << i)))
        {
            X ^= 1 << i;
        }
    }

    Y = (1 << last0);

    return X ^ Y;
}

int main()
{
    cout << solve(4);
    return 0;
}
