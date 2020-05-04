string Solution::solve(string A) {
    queue<char> q;
    unordered_map<char,int> visited;
    string ans = "";
    for (int i = 0; i < A.size(); i++)
    {
        if(visited[A[i]]==0){
            visited[A[i]]=1;
            q.push(A[i]);
        }
        else
            visited[A[i]]++;
        while (!q.empty() && visited[q.front()]!=1)
            q.pop();
        
        if(q.empty())
            ans += "#";
        else
            ans += q.front();
    }
    return ans;
}