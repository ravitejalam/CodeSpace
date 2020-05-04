vector<int> Solution::solve(vector<int> &A) {
    stack<int> main,tmp;
    main.push(A[0]);
    for(int i =1; i<A.size();i++){
        if(main.top()<=A[i]){
            main.push(A[i]);
        }
        else{
            while(!main.empty() && main.top()>A[i]){
                int e = main.top();
                main.pop();
                tmp.push(e);
            }
            main.push(A[i]);
            while(!tmp.empty()){
                int e = tmp.top();
                tmp.pop();
                main.push(e);
            }
        }
    }
    for(int i = A.size()-1;i>=0;i--){
        A[i] = main.top();
        main.pop();
    }
    return A;
}
