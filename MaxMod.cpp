int Solution::solve(vector<int> &A) {
    int a =2;
    for(int i = 0 ; i<a;i++){
        for(int j = 1 ; j<A.size();j++){
            if(A[j]<A[j-1])
                swap(A[j],A[j-1]);
        }
        if(i!=0 && A[A.size()-1-i]==A[A.size()-i])
            a++;
    }
    return A[A.size()-a];
}
