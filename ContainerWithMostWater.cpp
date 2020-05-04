int Solution::maxArea(vector<int> &A) {
    if(A.size()<2) return 0;
    int left = 0, right = A.size()-1;
    long long int area = INT_MIN;
    while (left<right)
    {
        long long int currArea = min(A[left],A[right])*(right-left);
        area = max(area,currArea);
        if(A[left]<A[right])
            left++;
        else
            right--;
    }
    return area;
}