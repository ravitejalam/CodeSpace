#include <bits/stdc++.h>

using namespace std;

string solve(string A, string B) {
    if(A==B)
        return A;
    else
        return "1";
}

int main()
{
    cout << solve("1","3");
    return 0;
}
