int Solution::solve(vector<int> &A)
{
    vector<pair<int, int>> stack;
    int ans = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++)
    {
        if (stack.empty())
        {
            stack.push_back(make_pair(A[i], 1));
        }
        else
        {
            if (stack.back().first == A[i])
            {
                stack.back().second++;
                if (stack.back().second == 3)
                    stack.back().second = 1;
            }
            else
            {
                stack.push_back(make_pair(A[i], 1));
            }
        }
    }
    int doublePairs = 0;
    for (int i = 0; i < stack.size(); i++)
    {
        if (stack[i].second == 1)
        {
            ans++;
        }
        else
        {
            doublePairs++;
        }
    }
    return ans + 2 * (doublePairs / 2);
}