#define M 1000000007

int Solution::solve(vector<int> &A, int B)
{
    long long int sum = 0;
    deque<int> GrtElmtIndx;
    deque<int> SmlElmtIndx;

    for (int i = 0; i < B; i++)
    {
        while (!GrtElmtIndx.empty() && A[GrtElmtIndx.back()] <= A[i])
            GrtElmtIndx.pop_back();

        while (!SmlElmtIndx.empty() && A[SmlElmtIndx.back()] >= A[i])
            SmlElmtIndx.pop_back();

        GrtElmtIndx.push_back(i);
        SmlElmtIndx.push_back(i);
    }

    for (int i = B; i < A.size(); i++)
    {
        sum = (sum + M + A[GrtElmtIndx.front()]) % M;
        sum = (sum + M + A[SmlElmtIndx.front()]) % M;

        while (!SmlElmtIndx.empty() && SmlElmtIndx.front() <= i - B)
            SmlElmtIndx.pop_front();

        while (!GrtElmtIndx.empty() && GrtElmtIndx.front() <= i - B)
            GrtElmtIndx.pop_front();

        while (!SmlElmtIndx.empty() && A[SmlElmtIndx.back()] >= A[i])
            SmlElmtIndx.pop_back();

        while (!GrtElmtIndx.empty() && A[GrtElmtIndx.back()] <= A[i])
            GrtElmtIndx.pop_back();

        GrtElmtIndx.push_back(i);
        SmlElmtIndx.push_back(i);
    }

    sum = (sum + M + A[GrtElmtIndx.front()]) % M;
    sum = (sum + M + A[SmlElmtIndx.front()]) % M;

    return sum;
}