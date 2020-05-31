bool sfun(vector<int> &A,vector<int> &B){
	if(A[0] * A[0] + A[1] * A[1] < B[0] * B[0] + B[1] * B[1])
		return true;
	return false;
}

vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
	sort(A.begin(),A.end(),sfun);
	while (A.size()>B){
		A.pop_back();
	}
	return A;
}