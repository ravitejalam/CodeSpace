#include <bits/stdc++.h>

using namespace std;

void updateAns(vector<int> &Array, int &maxSum, int currentIndex, int currentSum, int currentSubSeqSize, vector<int> &postSum, int &ans, int &subSeqSize)
{
    if (currentIndex == Array.size())
    {
        if (currentSum <= maxSum and currentSubSeqSize == subSeqSize)
            ans++;
        return;
    }

    if (currentSum > maxSum or currentSubSeqSize > subSeqSize)
    {
        return;
    }

    if (currentSum <= maxSum and currentSubSeqSize == subSeqSize)
    {
        ans++;
        return;
    }
    updateAns(Array, maxSum, currentIndex + 1, currentSum, currentSubSeqSize, postSum, ans, subSeqSize);
    updateAns(Array, maxSum, currentIndex + 1, currentSum + Array[currentIndex], currentSubSeqSize + 1 , postSum, ans, subSeqSize);
}

int solve(vector<int> &A, int B)
{
    vector<int> postSum = {};
    int subSeqSize = 1000;
    postSum.push_back(A.back());
    for (int i = A.size() - 2; i >= 0; i--)
    {
        postSum.push_back(postSum.back() + A[i]);
    }
    int ans = 0;
    reverse(postSum.begin(),postSum.end());
    updateAns(A, subSeqSize, 0, 0, 0, postSum, ans, B);
    return ans;
}