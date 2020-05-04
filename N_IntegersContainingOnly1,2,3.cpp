vector<int> Solution::solve(int A) {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    vector<int> ans(A);
    int ind = 0;
    for (int i = 3; i < A; i+3)
    {
        q.push(q.front()*10 + 1);
        q.push(q.front()*10 + 2);
        q.push(q.front()*10 + 3);
        ans[ind]=q.front();
        q.pop();
        ind++;
    }
    for (int i = ind; i < A; i++)
    {
        ans[i] = q.front();
        q.pop();
    }
    return ans;
}vector<int> Solution::solve(int A) {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    vector<int> ans(A);
    int ind = 0;
    for (int i = 3; i < A; i+=3)
    {
        q.push(q.front()*10 + 1);
        q.push(q.front()*10 + 2);
        q.push(q.front()*10 + 3);
        ans[ind]=q.front();
        q.pop();
        ind++;
    }
    for (int i = ind; i < A; i++)
    {
        ans[i] = q.front();
        q.pop();
    }
    return ans;
}