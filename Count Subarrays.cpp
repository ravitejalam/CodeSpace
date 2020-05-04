#define M 1000000007

int Solution::solve(vector<int> &A) {
    int left = 0;
    int right = 0;
    long long int ans = 0;
    set<int> s = {};
    while (left<A.size() && right<A.size())
    {
        if (s.find(A[right]) == s.end())
        {
            s.insert(A[right]);
        }
        else{
            // ans =(ans+ (right-left+1)*(right-left)/2)%M;
            while (A[left]!=A[right])
            {
                s.erase(A[left]);
                left++;
            }            
            left++;
        }
        right++;
        ans = (ans+right-left)%M;
    }
    // ans =(ans+ (right-left+1)*(right-left)/2)%M;
    return ans;
}