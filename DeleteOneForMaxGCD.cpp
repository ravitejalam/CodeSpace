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
    int s = A.size();
    vector<int> pre(s,0),post(s,0);
    pre[0] = A[0];
    post[s-1]=A[s-1];
    for(int i = 1; i<s;i++){
        pre[i] = gcd(pre[i-1],A[i]);
        post[s-i-1] = gcd(post[s-i],A[s-i-1]);
    }
    int m = post[1];
    for(int i = 1 ;i<s-1;i++){
        m = max(m,gcd(pre[i-1],post[i+1]));
    }
    return max(m,pre[s-2]);
}

int main()
{
    vector<int> A = {12, 15, 18};
    cout << solve(A);
    return 0;
}
