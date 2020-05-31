int count(const vector<int> &A, int B)
{
	int c = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] <= B)
			c++;
	}
	return c;
}

int Solution::kthsmallest(const vector<int> &A, int B)
{
	int start = *min_element(A.begin(), A.end());
	int end = *max_element(A.begin(), A.end());
	int ans = -1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (B <= count(A, mid))
		{
			end = mid - 1;
			ans = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	return ans;
}