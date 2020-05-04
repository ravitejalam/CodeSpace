vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    vector<int> ans(B.size());
    vector<int> pre(A.size()+1);
    for (int i = 1; i <= A.size(); i++)
    {
        pre[i] = pre[i-1]+A[i-1];
    }
    for (int i = 0; i < B.size(); i++)
    {
        int l = B[i][0];
        int r = B[i][1];
        int L = B[i][2];
        int R = B[i][3];
        if(l-r!=L-R)
            ans[i] = 0;
        else if(pre[r+1]-pre[l] != pre[R+1]-pre[L])
        {
            ans[i] = 0;
        }
        else
        {
            bool flag = true;
            unordered_map<int,int> first,second;
            for (int f = l; f <= r; f++)
                first[A[f]]++;
            for (int s = L; s <= R; s++)
                second[A[s]]++;
            for (int c = l; c <= r; c++)
            {
                if(first[A[c]]!=second[A[c]]){
                    flag = false;
                    ans[i]=0;
                    break;
                }
            }
            if(flag)
                ans[i]=1;
        }
    }
    return ans;
}