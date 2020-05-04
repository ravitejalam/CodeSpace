vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string,vector<int>> list;
    vector<string> AA(A.size());
    vector<vector<int>> ans;
    for (int i = 0; i < AA.size(); i++)
    {
        AA[i]=A[i];
        sort(AA[i].begin(),AA[i].end());
        list[AA[i]].push_back(i+1);
    }
    for (auto x: list)
    {
        ans.push_back(x.second);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
