struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    maxHeap.push(make_pair(A.back() + B.back(), make_pair(A.size() - 1, B.size() - 1)));
    unordered_map<pair<int, int>, bool, hash_pair> visited_pairs;
    vector<int> ans;
    visited_pairs[make_pair(A.size() - 1, A.size() - 1)] = true;
    for (int i = 0; i < A.size(); i++)
    {
        pair<int, pair<int, int>> mx = maxHeap.top();
        visited_pairs[mx.second] = true;
        maxHeap.pop();
        int x = mx.second.first;
        int y = mx.second.second;
        if (x > 0 && y > -1 && visited_pairs[make_pair(x - 1, y)] == false)
        {
            visited_pairs[make_pair(x - 1, y)] = true;
            maxHeap.push(make_pair(A[x - 1] + B[y], make_pair(x - 1, y)));
        }
        if (x > -1 && y > 0 && visited_pairs[make_pair(x, y - 1)] == false)
        {
            visited_pairs[make_pair(x, y - 1)] = true;
            maxHeap.push(make_pair(A[x] + B[y - 1], make_pair(x, y - 1)));
        }
        ans.push_back(mx.first);
    }
    return ans;
}