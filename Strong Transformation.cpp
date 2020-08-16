#include <bits/stdc++.h>
using namespace std;

int solve(string A, string B)
{
    unordered_map<char, char> map;
    for (int i = 0; i < A.length(); i++)
    {
        if (map[A[i]])
        {
            if (map[A[i]] != B[i])
                return 0;
        }
        else
        {
            map[A[i]] = B[i];
        }
    }
    return map.size() == 26 ? 0 : 1;
}

int main(int argc, char const *argv[])
{
    cout << solve("abcab", "abcdb");
    return 0;
}
