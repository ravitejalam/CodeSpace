vector<int> Solution::equal(vector<int> &A)
{
    unordered_map<int, pair<int, int>> sum;
    vector<int> ans(4,INT_MAX);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            int s = A[i] + A[j];
            if (sum.find(s) != sum.end())
            {
                int I = sum[s].first;
                int J = sum[s].second;
                if(J!=i && J!=j && I<i){
                    vector<int> B = {I,J,i,j};
                    if(ans>B)
                        ans = {I,J,i,j};
                }
            }
            else
            {
                sum[s] = pair(i, j);
            }
        }
    }
    return ans;
}