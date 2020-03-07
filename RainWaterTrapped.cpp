#include <bits/stdc++.h>

using namespace std;

int trap(const vector<int> &A) {
    int s = A.size();
    vector<int> leftMax(s,0), rightMax(s,0);
    for (int i = 1 ; i < s; i++){
        leftMax[i] = max(leftMax[i-1],A[i-1]);
    }
    for (int i = s-2 ; i >= 0 ; i--){
        rightMax[i] = max(rightMax[i+1],A[i+1]);
    }
    int cost = 0;
    for (int i = 0; i < s ; i++){
        int tmp = min(leftMax[i],rightMax[i]) - A[i];
        cost += tmp > 0 ? tmp : 0 ;
    }
    return cost;
}

int main()
{
    vector<int> A = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(A);
    return 0;
}
