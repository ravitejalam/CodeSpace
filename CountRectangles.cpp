int Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map<int,unordered_set<int>> points;
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
        points[A[i]].insert(B[i]);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i+1; j < A.size(); j++)
        {
            if(A[i]!=A[j] && B[i]!=B[j]){
                if(points[A[i]].find(B[j]) != points[A[i]].end() && points[A[j]].find(B[i]) != points[A[j]].end())
                    ans++;
            }
        }
    }
    return ans/2;
}