int Solution::solve(string A) {
    stack<char> s;
    for(int i=0 ; i<A.length();i++){
        switch(A[i]) {
            case '{':
            case '(':
            case '[':
                s.push(A[i]);
                break;
            case '}':
                if(s.empty())
                    return 0;
                else if(s.top() == '{')
                    s.pop();
                else
                    return 0;
                break;
            case ')':
                if(s.empty())
                    return 0;
                else if(s.top() == '(')
                    s.pop();
                else
                    return 0;
                break;
            case ']':
                if(s.empty())
                    return 0;
                else if(s.top() == '[')
                    s.pop();
                else
                    return 0;
                break;
            default:
                break;
        }
    }
    if(s.empty())
        return 1;
    return 0;
}
