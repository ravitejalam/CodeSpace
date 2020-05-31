bool hasOnlyOneChild(vector<int> &A) 
{ 
    int size = A.size();
	int mini, maxi; 
    if (A[size-1] > A[size-2]) 
    { 
        maxi = A[size-1]; 
        mini = A[size-2];
    }
    else
    { 
        maxi = A[size-2]; 
        mini = A[size-1]; 
    }
    for (int i=size-3; i>=0; i--) 
    { 
        if (A[i] < mini) 
            mini = A[i]; 
        else if (A[i] > maxi) 
            maxi = A[i]; 
        else
            return false; 
    } 
    return true; 
}

string Solution::solve(vector<int> &A)
{
	if (hasOnlyOneChild(A) == true ) 
		return "YES" ;
	return "NO";
}
