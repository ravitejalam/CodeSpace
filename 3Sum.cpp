long long int getClosestSum(vector<int> &A, int sum, int start, int end)
{
    long long int closestSum;
    if (sum < 0)
        closestSum = INT_MAX;
    else
        closestSum = INT_MIN;
    while (start < end)
    {
        int currSum = A[start] + A[end];
        if (currSum == sum)
            return sum;
        else if (currSum < sum)
            start++;
        else
            end--;
        if (abs(currSum - sum) < abs(closestSum - sum))
            closestSum = currSum;
    }
    return closestSum;
}

int Solution::threeSumClosest(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    long long int closestSum;
    if (B < 0)
        closestSum = INT_MAX;
    else
        closestSum = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        long long int tmp = getClosestSum(A,B-A[i],i+1,A.size()-1)+A[i];
        if (abs(tmp - B) < abs(closestSum - B))
            closestSum = tmp;
    }
    return closestSum;
}