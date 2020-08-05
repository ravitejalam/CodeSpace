vector<int> Solution::solve(int A, int B, vector<int> &C)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < B; i++)
    {
        minHeap.push(C[i]);
        maxHeap.push(C[i]);
    }
    vector<int> ans(2, 0);
    for (int i = 0; i < A; i++)
    {
        ans[0] += maxHeap.top();
        int top = maxHeap.top();
        maxHeap.pop();
        top--;
        if (top)
            maxHeap.push(top);
        ans[1] += minHeap.top();
        top = minHeap.top();
        minHeap.pop();
        top--;
        if (top)
            minHeap.push(top);
    }

    return ans;
}