int largestRectangleArea(vector<int> &A)
{
    stack<int> s;
    int n = A.size();
    int max_area = 0;
    int tp;
    int area_with_top;

    int i = 0;
    while (i < n)
    {
        if (s.empty() || A[s.top()] <= A[i])
            s.push(i++);
        else
        {
            tp = s.top();
            s.pop();
            area_with_top = A[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = A[tp] * (s.empty() ? i : i - s.top() - 1);
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}

int Solution::maximalRectangle(vector<vector<int>> &A)
{
    int maxRec = largestRectangleArea(A[0]);
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            A[0][j] = A[i][j] == 0 ? 0 : A[0][j] + 1;
        }
        maxRec = max(maxRec, largestRectangleArea(A[0]));
    }
    return maxRec;
}