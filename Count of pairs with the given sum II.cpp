
#define M 1000000007

int Solution::solve(vector<int> &A, int B) {
    vector<vector<long long int>> s = {{A[0],1}};
    for (int i = 1; i < A.size(); i++)
    {
        if(A[i]==s.back()[0]){
            s.back()[1]++;
        }
        else{
            s.push_back({A[i],1});
            s.back()[1]%=M;
        }
    }
    int left = 0;
    int right = s.size()-1;
    long long int ans = 0;
    while (left<=right)
    {
        int sum = s[left][0]+s[right][0];
        if(sum==B){
            if(left==right)
                ans = (ans + ((s[left][1]*(s[right][1]-1))/2)%M)%M;
            else
                ans = (ans + (s[left][1]*s[right][1])%M)%M;
            left++;
        }
        else if(sum<B){
            left++;
        }
        else{
            right--;
        }
    }
    return ans;
}