int Solution::largestRectangleArea(vector<int> &A) {
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
