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
    set<int> alreadyCovered = {};
    for (int i = index; i < A.size(); i++)
    {
        if(find(alreadyCovered.begin(), alreadyCovered.end(), A[i]) == alreadyCovered.end()){
            swap(A,i,index);
            allPermutations(A,index+1,ans);
            swap(A,i,index);
            alreadyCovered.insert(A[i]);
        }
    }
    
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans = {};
    allPermutations(A,0,ans);
    return ans;
}