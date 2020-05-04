bool isPossible(vector<int> &V, int M, int curMin) {
    int studentsRequired = 1;
    int curSum = 0;
    for (int i = 0; i < V.size(); i++) {
        if (V[i] > curMin) return false;
        if (curSum + V[i] > curMin) {
            studentsRequired++;
            curSum = V[i]; 
            if (studentsRequired > M) return false;
        } else {
            curSum += V[i];
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    long long sum = 0;
    int N = A.size();

    if(N < B)
        return -1;

    for(int i = 0; i < N; ++i) {
        sum += A[i];
    }

    long long start = 0;
    long long end = sum, mid;
    int ans = INT_MAX; 
    while(start <= end) {
        mid = (start + end) / 2;
        if (isPossible(A, B, mid)) {
            ans = min(ans, (int)mid);
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}
