#include <bits/stdc++.h>

using namespace std;

unsigned int reverse(unsigned int A)
{
    unsigned int rev = 0;

    for (int i = 0; i < 32; i++)
    {
        rev <<= 1;
        if (A & 1 == 1)
            rev ^= 1;
        A >>= 1;
    }
    return rev;
}
int main()
    {
        cout << reverse(3);
        return 0;
    }
