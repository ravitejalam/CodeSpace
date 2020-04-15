#include <bits/stdc++.h>

using namespace std;

void palindromePartitioning(string &A, int prevPartition, int index, vector<vector<bool>> &isPalindrome, vector<string> currentAns, vector<vector<string>> &ans)
{
    if (index == A.size()-1)
    {
        if(isPalindrome[prevPartition][index]){
            currentAns.push_back(A.substr(prevPartition, index - prevPartition + 1));
            ans.push_back(currentAns);
            currentAns.pop_back();
        }
        return;
    }
    if (isPalindrome[prevPartition][index])
    {
        currentAns.push_back(A.substr(prevPartition, index - prevPartition + 1));
        palindromePartitioning(A, index + 1, index + 1, isPalindrome, currentAns, ans);
        currentAns.pop_back();
    }
    palindromePartitioning(A, prevPartition, index + 1, isPalindrome, currentAns, ans);
}

void updateIsPalindrome(string &A, int start, int end, vector<vector<bool>> &isPalindrome)
{
    int x = start, y = end;
    while (start < end)
    {
        if (A[start] == A[end])
        {
            start++;
            end--;
        }
        else
        {
            return;
        }
    }
    isPalindrome[x][y] = true;
}

vector<vector<string>> partition(string A)
{
    vector<vector<string>> ans = {};
    vector<string> currentAns = {};
    vector<vector<bool>> isPalindrome(A.size(), vector<bool>(A.size(), false));
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i; j < A.size(); j++)
        {
            updateIsPalindrome(A, i, j, isPalindrome);
        }
    }
    palindromePartitioning(A, 0, 0, isPalindrome, currentAns, ans);
    return ans;
}