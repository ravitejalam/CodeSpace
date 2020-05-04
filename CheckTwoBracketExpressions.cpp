string getString(string s){
    stack<char> st;
    stack<bool> flag;
    flag.push(true);
    for(int i = 0;i<s.length();i++){
        switch(s[i]) {
            case '(':
                if(st.empty()){
                    flag.push(true);
                    break;
                }
                if(st.top() == '+')
                    flag.push(flag.top());
                else
                    flag.push(!flag.top());
                break;
            case ')':
                flag.pop();
                break;
            case '+':
                if(flag.top())
                    st.push('+');
                else
                    st.push('-');
                break;
            case '-':
                if(flag.top())
                    st.push('-');
                else
                    st.push('+');
                break;
            default:
                st.push(s[i]);
                break;
        }
    }
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

int Solution::solve(string A, string B) {
    A = getString(A);
    B = getString(B);
    if( A == B )
        return 1;
    return 0;
}
