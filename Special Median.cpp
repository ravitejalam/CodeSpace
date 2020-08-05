int isSpecial(vector<int> &A){
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
    for (int i = 0; i < A.size(); i++)
    {
        if (leftHeap.empty())
        {
            leftHeap.push(A[i]);
            continue;
        }
        int total_ele = leftHeap.size() + rightHeap.size();
        if (total_ele & 1)
        {
            if (leftHeap.top() == A[i])
                return 1;
        }
        else
        {
            double mid = (1.0*(leftHeap.top() + rightHeap.top())) / 2;
            if (mid == 1.0*A[i])
                return 1;
        }
        if (total_ele & 1)
        {
            leftHeap.push(A[i]);
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
        else
        {
            rightHeap.push(A[i]);
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }
    return 0;
}

int Solution::solve(vector<int> &A)
{
    if(isSpecial(A)==1)
        return 1;
    reverse(A.begin(),A.end());
    if(isSpecial(A))
        return 1;
    return 0;
}