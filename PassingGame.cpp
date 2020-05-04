int Solution::solve(int A, int B, vector<int> &C) {
    stack<int> backPass;
    int prev = B;
    backPass.push(B);
    for(int i =0;i<C.size();i++){
        if(C[i]==0){
            int tmp = backPass.top();
            backPass.push(prev);
            prev = tmp;
        }
        else{
            prev = backPass.top();
            backPass.push(C[i]);
        }
    }
    return backPass.top();
}
