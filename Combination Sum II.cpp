void allSubsets(vector<int> &A, vector<int> combination, int index, int prevSum, vector<vector<int>> &ans, int expSum)
{
    if (prevSum == expSum and find(ans.begin(), ans.end(), combination) == ans.end())
    {
        ans.push_back(combination);
        return;
    }
    if (index >= A.size() or prevSum > expSum)
        return;
    allSubsets(A, combination, index + 1, prevSum, ans, expSum);
    combination.push_back(A[index]);
    prevSum += A[index];
    allSubsets(A, combination, index + 1, prevSum, ans, expSum);
}

vector<vector<int>> Solution::combinationSum(vector<int> &A, int B)
{
    vector<vector<int>> ans = {};
    sort(A.begin(), A.end());
    allSubsets(A, {}, 0, 0, ans, B);
    sort(ans.begin(), ans.end());
    return ans;
}