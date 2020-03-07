#include <bits/stdc++.h>

using namespace std;

int solve(int A, int B) {
    return max(A,B)-min(A,B);
}

int main()
{
    cout << solve(1,2);
    return 0;
}
