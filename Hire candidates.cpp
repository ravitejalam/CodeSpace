long long int minAmountToHire(long long int count, vector<int> &cost)
{
    vector<long long int> temp(cost.size());
    for (int i = 0; i < cost.size(); i++)
    {
        temp[i] = cost[i] + 1LL * (i + 1) * count;
    }
    sort(temp.begin(), temp.end());
    long long int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += temp[i];
    }
    return sum;
}

vector<int> Solution::solve(int A, vector<int> &B)
{
    int low = 0;
    int high = B.size();
    vector<int> ans = {0, 0};
    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        long long int minAmt = minAmountToHire(mid, B);
        if (A >= minAmt)
        {
            ans[0] = mid;
            ans[1] = minAmt;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
