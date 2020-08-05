struct MyCompare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first + a.second > b.first + b.second;
    }
};

int Solution::solve(vector<int> &A, int B)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> minHeap;
    for (int i = 0; i < A.size(); i++)
    {
        minHeap.push(make_pair(A[i], A[i]));
    }
    for (int i = 0; i < B; i++)
    {
        pair<int, int> top = minHeap.top();
        minHeap.pop();
        minHeap.push(make_pair(top.first + top.second, top.second));
    }
    int ans = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        ans = max(ans, minHeap.top().first);
        minHeap.pop();
    }
    return ans;
}