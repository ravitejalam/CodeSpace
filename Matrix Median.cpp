int binarySearch(vector<int> &row, int element){
    int s = row.size(), left = 0, right = s - 1, mid = 0, index = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (row[mid] < element)
        {
            index = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return index;
}

bool countMatrix(vector<vector<int> > &A,int element){
    int count = 0;
    for (int i = 0; i < A.size(); i++)
    {
        count+= binarySearch(A[i],element)+1;
    }
    if(count<=(A.size()*A[0].size())/2)
        return true;
    return false;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int s = A.size(), left = INT_MAX, right = INT_MIN, mid = 0, ans = -1;
    for (int i = 0; i < s; i++)
    {
        left = min(left,A[i][0]);
        right = max(right,A[i].back());
    }
    
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (countMatrix(A,mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}