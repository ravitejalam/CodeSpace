string Solution::solve(string A) {
    unordered_set<char> visited;
    unordered_map<char,int> freq;
    for (int i = 0; i < A.length(); i++)
    {
        freq[A[i]]++;
    }
    stack<char> st;
    for (int i = 0; i < A.length(); i++)
    {
        if(st.empty()){
            st.push(A[i]);
            visited.insert(A[i]);
            freq[A[i]]--;
        }
        else
        {
            if(visited.find(A[i]) == visited.end()){
                while(!st.empty() && freq[st.top()]>0 && st.top()>A[i]){
                    visited.erase(st.top());
                    st.pop();
                }
                st.push(A[i]);
                visited.insert(A[i]);
                freq[A[i]]--;
            }
            else{
                freq[A[i]]--;
            }
        }
    }
    string s = "";
    while (!st.empty())
    {
        s += st.top();
        st.pop();
    }
    reverse(s.begin(),s.end());
    return s;
}
