int Solution::braces(string A) {
    stack<int> s;
    for(int i = 0;i<A.length();i++){
        if(A[i] == '(' || A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/'){
            s.push(A[i]);
        }
        else if(A[i] == ')'){
            if(s.empty()){
                return 1;
            }
            else if(s.top() == '('){
                return 1;
            }
            else{
                while(!s.empty() && s.top()!='('){
                    s.pop();
                }
                if(!s.empty() && s.top()=='('){
                    s.pop();
                }
                else{
                    return 1;
                }
            }
        }
    }
    while(!s.empty() && s.top()!='(' && s.top()!=')')
        s.pop();
    if(s.empty())
        return 0;
    else
        return 1;
}
