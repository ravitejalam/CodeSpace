int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int> s = {};
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        s.insert(A[i]);
    }
    unordered_set<int> visited = {};
    for (int i = 0; i < A.size(); i++)
    {
        if(visited.find(A[i]) == visited.end()){
            if(s.find(A[i]-1) == s.end()){
                int len = 1;
                int num = A[i];
                while (s.find(num+1) != s.end())
                {
                    num++;
                    len++;
                }
                ans=max(ans,len);
            }
            visited.insert(A[i]);
        }
    }
    return ans;
}