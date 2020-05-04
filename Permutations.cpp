bool compare(vector<int> &A, vector<int> &B)
{
    for (int i = 0; i < 26; i++)
    {
        if (A[i] != B[i])
            return false;
    }
    return true;
}

int Solution::solve(string A, string B)
{
    int ans = 0;
    vector<int> aCount(26);
    for (int i = 0; i < A.size(); i++)
    {
        aCount[A[i] - 'a']++;
    }
    vector<int> bCount(26);
    int left = 0;
    int right = 0;
    while (right<B.size())
    {
        bCount[B[right] - 'a']++;
        if(right-left+1==A.size()){
            if (compare(aCount,bCount))
                ans++;
            bCount[B[left] - 'a']--;
            left++;
        }
        right++;
    }
    return ans;
}