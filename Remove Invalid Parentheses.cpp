#include <bits/stdc++.h>
using namespace std;

void updateAns(string prefix, string &A, int index, int &minOperations, int currOperations, int value, set<string> &ans)
{
    if (currOperations > minOperations)
        return;
    if (value < 0)
        return;
    if (index == A.length())
    {
        if (value == 0)
            ans.insert(prefix);
        return;
    }
    if (A[index] == ')')
    {
        updateAns(prefix, A, index + 1, minOperations, currOperations + 1, value, ans);
        updateAns(prefix + A[index], A, index + 1, minOperations, currOperations, value - 1, ans);
    }
    else if (A[index] == '(')
    {
        updateAns(prefix, A, index + 1, minOperations, currOperations + 1, value, ans);
        updateAns(prefix + A[index], A, index + 1, minOperations, currOperations, value + 1, ans);
    }
    else
    {
        updateAns(prefix + A[index], A, index + 1, minOperations, currOperations, value, ans);
    }
}

vector<string> solve(string A)
{
    int minOperations;
    int left = 0;
    int right = 0;
    for (char c : A)
    {
        if (c == '(')
        {
            left++;
        }
        else if (c == ')')
        {
            if (left)
                left--;
            else
                right++;
        }
    }
    minOperations = left + right;
    set<string> tmp_ans;
    updateAns("", A, 0, minOperations, 0, 0, tmp_ans);
    vector<string> ans;
    for (string s : tmp_ans)
        ans.push_back(s);
    return ans;
}

int main(int argc, char const *argv[])
{
    string input = "(a)())()";
    vector<string> result = solve(input);
    return 0;
}
