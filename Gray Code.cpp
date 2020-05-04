void updateAns(int &index,vector<int> &ans,int &A){
    if(index<A){
        int s = ans.size();
        for (int i = s-1; i >= 0; i--)
        {
            ans.push_back(ans[i]+(1<<index));
        } 
        index++;
        updateAns(index,ans,A);
    }
}

vector<int> Solution::grayCode(int A) {
    vector<int> ans;
    int index = 1;
    ans.push_back(0);
    ans.push_back(1);
    updateAns(index,ans,A);
    return ans;
}