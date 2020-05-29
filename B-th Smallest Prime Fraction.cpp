struct Data
{
    int p;
    int q;
    double f;
    Data(int P, int Q, double F) 
        : p(P), q(Q) ,f(F)
    { 
    }
};

struct CompareHeight { 
    bool operator()(Data a, Data b)
    {
        if (a.f > b.f)
            return true;
        return false;
    }
};

vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<Data> v;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; j++)
        {
            Data d = Data(A[i],A[j],(1.0 * A[i]) / A[j]);
            v.push_back(d);
        }
    }

    priority_queue<Data, vector<Data>, CompareHeight> minHeap(v.begin(), v.end());

    Data val = Data(-1,-1,0.0);
    for (int i = 0; i < B; i++)
    {
        val = minHeap.top();
        minHeap.pop();
    }
    vector<int> ans = {val.p, val.q};
    return ans;
}