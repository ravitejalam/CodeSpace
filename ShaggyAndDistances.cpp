int Solution::solve(vector<int> &A) {
    unordered_map<int,int> lastIndex = {};
    int ans = INT_MAX;
    for (int i = 0; i < A.size(); i++)
    {
        if (lastIndex.find(A[i]) == lastIndex.end())
        {
            lastIndex.insert(pair(A[i],i));
        }
        else
        {
            ans = min(ans,i-lastIndex[A[i]]);
            lastIndex[A[i]] = i;
        }              
    }
    if(ans==INT_MAX)
        return -1;
    return ans;
}