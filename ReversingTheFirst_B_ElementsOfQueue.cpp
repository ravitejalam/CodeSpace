vector<int> Solution::solve(vector<int> &A, int B) {
    deque<int> dq;
    for (int i = 0; i < A.size(); i++)
    {
        if(i<B)
            dq.push_front(A[i]);
        else
            dq.push_back(A[i]);
    }
    vector<int> ans(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        ans[i]=dq.at(0);
        dq.pop_front();
    }
    return ans;
}
