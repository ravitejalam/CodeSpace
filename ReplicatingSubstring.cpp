int Solution::solve(int A, string B) {
    unordered_map<char,int> count;
    for (int i = 0; i < B.size(); i++)
    {
        count[B[i]]++;
    }
    for (auto ch: count)
    {
        if(ch.second%A!=0)
            return -1;
    }
    return 1;
}