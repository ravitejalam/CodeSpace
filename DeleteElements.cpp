#include <bits/stdc++.h>

using namespace std;

int gcd(int A, int B) {
    if(A==0)
        return B;
    else if(B==0)
        return A;
    else if(A<=B)
        return gcd(A,B%A);
    else
        return gcd(B,A%B);
}

int solve(vector<int> &A) {
    int gcdd=A[0];
    for(int i =1 ;i<A.size();i++){
        gcdd=gcd(gcdd,A[i]);
    }
    if(gcdd==1){
        return 0;
    }
    else{
        return -1;
    }
}

int main()
{
    vector<int> A = {7, 2, 5};
    cout << solve(A);
    return 0;
}