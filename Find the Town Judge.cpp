#include <bits/stdc++.h>

using namespace std;

int findJudge(int N, vector<vector<int>> &trust)
{
    vector<int> trusties(N + 1);
    unordered_set<int> fools;
    for (int i = 0; i < trust.size(); i++)
    {
        trusties[trust[i][1]] += 1;
        fools.insert(trust[i][0]);
    }
    for (int t = 1; t <= N; t++)
    {
        if (trusties[t] == N - 1 && fools.find(t) == fools.end())
            return t;
    }
    return -1;
}

int main()
{
    vector<vector<int>> i = {{1,3},{1,4},{2,3},{2,4},{4,3}};
    cout << findJudge(4, i);
    return 0;
}
