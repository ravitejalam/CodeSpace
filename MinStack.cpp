stack<long long int> st;
int mini;

MinStack::MinStack() {
    while(!st.empty())
        st.pop();
    mini = INT_MAX;
}

void MinStack::push(int x) {
    if(st.empty()){
        mini = x;
        st.push(x);
    }
    else{
        if(x<mini){
            st.push(2*x-mini);
            mini=x;
        }
        else{
            st.push(x);
        }
    }
    // cout << "pushed" << endl;

}

void MinStack::pop() {
    if(!st.empty()){
        int x = st.top();
        if(x<mini){
            mini = 2*mini-x;
        }
        st.pop();
    }
}

int MinStack::top() {
    if(!st.empty()){
        if(st.top()<mini)
            return mini;
        else
            return st.top();   
    }
    return -1;
}

int MinStack::getMin() {
    if(st.empty())
        return -1;
    else
        return mini;
}

