#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &A)
{
    int max_e = *max_element(A.begin(), A.end());
    vector<int> result(max_e, 1);
    for (int i = 1; i < max_e; i++)
    {
        for (int j = i; j < max_e; j += i + 1)
        {
            result[j]++;
        }
    }
    vector<int> divisorsCount;
    for (int i = 0; i < A.size(); i++)
    {
        divisorsCount.push_back(result[A[i] - 1]);
    }
    return divisorsCount;
}

int main()
{
    vector<int> A = {2, 3, 4, 5};
    vector<int> B = solve(A);
    return 0;
}
