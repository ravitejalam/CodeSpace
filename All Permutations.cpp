void swap(vector<int> &A,int i,int j){
    int tmp = A[i];
    A[i]=A[j];
    A[j]=tmp;
}

void allPermutations(vector<int> &A,int index,vector<vector<int>> &ans){
    if(index==A.size()-1){
        ans.push_back(A);
        return;
    }
    for (int i = index; i < A.size(); i++)
    {
        swap(A,i,index);
        allPermutations(A,index+1,ans);
        swap(A,i,index);
    }
    
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans = {};
    allPermutations(A,0,ans);
    return ans;
}
