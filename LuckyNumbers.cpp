#include <bits/stdc++.h>

using namespace std;

int solve(int A)
{
    vector<int> counts(A + 1, 0);
    for (int i = 2; i <= A; i++)
    {
        if (counts[i] == 0)
        {
            for (int j = i; j <= A; j += i)
            {
                counts[j] += 1;
            }
        }
    }
    return count(counts.begin(), counts.end(), 2);
}

int main()
{
    cout << solve(8);
    return 0;
}
