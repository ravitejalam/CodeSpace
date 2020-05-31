vector<int> Solution::solve(vector<int> &A)
{
    priority_queue<int> leftMax;
    priority_queue<int, vector<int>, greater<int>> rightMin;
    vector<int> ans;
    leftMax.push(A[0]);
    int x = A[0];
    ans.push_back(leftMax.top());
    for (int i = 1; i < A.size(); i++)
    {
        x = A[i];
        if(leftMax.size()>rightMin.size()){
            leftMax.push(x);
            rightMin.push(leftMax.top());
            leftMax.pop();
        }
        else
        {
            rightMin.push(x);
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
        ans.push_back(leftMax.top());
    }
    return ans;
}