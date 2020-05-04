void insertAtBottom(vector<int> &A,int x){
    if(A.empty())
        A.push_back(x);
    else{
        int tmp = A.back();
        A.pop_back();
        insertAtBottom(A,x);
        A.push_back(tmp);
    }
}

void rev(vector<int> &A){
    if(A.size() == 0)
        return;
    int tmp = A.back();
    A.pop_back();
    rev(A);
    insertAtBottom(A,tmp);
}

vector<int> Solution::solve(vector<int> &A) {
    rev(A);
    return A;
}
