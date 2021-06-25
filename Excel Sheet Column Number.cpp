#include <bits/stdc++.h>

using namespace std;

int titleToNumber(string A)
{
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        ans = ans * 26 - 'A' + A[i] + 1;
    }
    return ans;
}

int main()
{
    cout << titleToNumber("AB");
    return 0;
}
