#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int i = 1; i< A.size();i++){
        if(abs(A[i]-A[i-1])!=1)
            return 0;
    }
    return 1;
}
