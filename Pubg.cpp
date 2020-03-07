#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A) {
    sort(A.begin(),A.end());
    int s = A.size();
    for(int i = 1 ; i < s ; i++){
        A[i] = A[i]%A[0];
        if(A[i]<A[0] && A[i]!=0){
            int tmp = A[0];
            A[0] = A[i];
            A[i] = tmp;
            i--;
        }
    }
    return A[0];
}

int main()
{
    vector<int> A = {4, 7 };
    cout << solve(A);
    return 0;
}
