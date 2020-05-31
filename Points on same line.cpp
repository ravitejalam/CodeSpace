int Solution::solve(vector<int> &A, vector<int> &B) {
    if (A.size() == 0 || B.size()==0)
		return 0;
	
	unordered_map<double,int> slopeMap;
	int ans = 1;
	for (int i = 0; i < A.size(); i++)
	{
		int dup = 1;
		int ver = 0;
		for (int j = i+1; j < A.size(); j++)
		{
			if (A[i]==A[j])
			{
				if (B[i]==B[j])
				{
					dup++;
				}
				else{
					ver++;
				}
			}
			else{
				double slope = 1.0 * (B[j]-B[i])/(A[j]-A[i]);
				slopeMap[slope]++;
			}
		}
		for (auto it = slopeMap.begin(); it != slopeMap.end(); it++)
			ans = max(ans,it->second+dup);
		ans = max(ans,ver+dup);
		slopeMap.clear();
	}
	return ans;
}
