vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> presum(A.size()+1,0);
    for (int i = 1; i <= A.size(); i++)
        presum[i]=presum[i-1]+A[i-1];
    int left = 0, right = 0;
    while (left<=right)
    {
        int sum = presum[right]-presum[left-1];
        if(sum == B){
            vector<int> ans = {};
            for (int i = left-1; i < right; i++)
            {
                if(A[i]==0)
                    continue;
                ans.push_back(A[i]);
            }
            return ans;
        }
        else if(sum < B)
            right++;
        else
        {
            left++;
        }
        if(right>A.size())
            break;
    }
    return {-1};
}