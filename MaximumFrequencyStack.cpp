vector<int> Solution::solve(vector<vector<int> > &A) {
    int maxFreq = 0;
    unordered_map<int,stack<int>> last;
    unordered_map<int,int> freq;
    vector<int> ans = {};
    for(int i=0;i<A.size();i++){
        if(A[i][0]==1){
            int currFreq = freq[A[i][1]];
            currFreq++;
            freq[A[i][1]] = currFreq;
            maxFreq = max(maxFreq,currFreq);
            last[currFreq].push(A[i][1]);
            ans.push_back(-1);
        }
        else{
            int e = last[maxFreq].top();
            last[maxFreq].pop();
            if(last[maxFreq].empty())
                maxFreq--;
            freq[e]--;
            ans.push_back(e);
        }
    }
    return ans;
}
