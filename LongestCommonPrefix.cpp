void buildZ(string str, int Z[]) 
{ 
	int n = str.length(); 
	int L, R, k;
	L = R = 0; 
	for (int i = 1; i < n; ++i) 
	{
		if (i > R) 
		{ 
			L = R = i;
			while (R<n && str[R-L] == str[R]) 
				R++; 
			Z[i] = R-L; 
			R--; 
		} 
		else
		{
			k = i-L;
			if (Z[k] < R-i+1) 
				Z[i] = Z[k];
			else
			{
				L = i; 
				while (R<n && str[R-L] == str[R]) 
					R++; 
				Z[i] = R-L; 
				R--; 
			} 
		} 
	}
    Z[0]=n;
}

string Solution::longestCommonPrefix(vector<string> &A) {
    string concat = "";
    for(int i =0 ;i<A.size();i++){
        concat = concat + "#" + A[i];
    }
	int l = concat.length();
	int Z[l]; 
	buildZ(concat, Z);
	int ansLen = INT_MAX;
	for(int i = 0 ;i<l;i++){
	    if(concat[i]=='#')
	        ansLen = min(ansLen,Z[i]);
	}
    return A[0].substr(0,ansLen-1);
}