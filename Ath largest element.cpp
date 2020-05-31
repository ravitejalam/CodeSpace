vector<int> Solution::solve(int A, vector<int> &B) {
    priority_queue<int,vector<int>,greater<int>> minHeap;
    vector<int> ans = {};
    for (int i = 0; i < B.size(); i++)
    {
        if(minHeap.size()<A-1){
            minHeap.push(B[i]);
            ans.push_back(-1);
        }
        else if(minHeap.size()==A-1){
            minHeap.push(B[i]);
            ans.push_back(minHeap.top());
        }
        else
        {
            if(minHeap.top()<B[i]){
                minHeap.pop();
                minHeap.push(B[i]);
            }
            ans.push_back(minHeap.top());
        }
    }
    return ans;
}