vector<int> Solution::solve(vector<int> &A, int B) {
    queue<int> q;
    for (int i = 0; i < B; i++)
    {
        if(A[i]<0)
            q.push(i);
    }
    vector<int> ans= {};
    for (int i = B; i < A.size(); i++)
    {
        if(q.empty())
            ans.push_back(0);
        else
            ans.push_back(A[q.front()]);

        while (!q.empty() && q.front()<=i-B)
            q.pop();

        if(A[i]<0)
            q.push(i);
    }
    if(q.empty())
        ans.push_back(0);
    else
        ans.push_back(A[q.front()]);
    return ans;
}