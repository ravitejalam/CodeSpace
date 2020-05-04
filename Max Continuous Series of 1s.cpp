vector<int> Solution::maxone(vector<int> &A, int B) {
    int currFlips = 0;
    int left = 0, right = 0;
    int start = 0,end=0;
    vector<int> ans = {};
    for (int i = 0; i < A.size(); i++)
    {
        if(A[right]==0){
            if(currFlips<B){
                currFlips++;
            }
            else
            {
                // if(currFlips!=0)
                //     currFlips--;
                while (A[left]!=0)
                {
                    left++;
                }
                left++;
            }
        }
        if(right-left+1>end-start){
            start = left;
            end = right+1;
        }
        right++;
    }
    for (int i = start; i < end; i++)
    {
        ans.push_back(i);
    }
    return ans;
}
