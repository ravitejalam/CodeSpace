int Solution::evalRPN(vector<string> &A)
{
    stack<int> st;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == "+"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a + b);
        }
        else if(A[i] == "-")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b - a);
        }
        else if(A[i] == "*"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a * b);
        }
        else if(A[i] == "/"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b / a);
        }
        else{
            st.push(stoi(A[i]));
        }
    }
    return st.top();
}