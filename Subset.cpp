void allSubsets(vector<int> &A, vector<int> s, int index, int size, vector<vector<int>> &ans)
{
    if (index == size)
    {
        ans.push_back(s);
        return;
    }
    allSubsets(A, s, index + 1, size, ans);
    s.push_back(A[index]);
    allSubsets(A, s, index + 1, size, ans);
}

vector<vector<int>> Solution::subsets(vector<int> &A)
{
    vector<vector<int>> ans ={};
    sort(A.begin(),A.end());
    allSubsets(A,{},0,A.size(),ans);
    sort(ans.begin(),ans.end());
    return ans;
}