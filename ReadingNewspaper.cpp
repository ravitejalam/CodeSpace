#include <bits/stdc++.h>

using namespace std;

int solve(int A, vector<int> &B) {
    int i = -1;
    while(A>0){
        i = (i+1)%7;
        A -= B[i];
    }
    return i+1;
}

int main()
{
    int A = 100;
    vector<int> B = {15, 20, 20, 15, 10, 30, 45};
    cout << solve(A,B);
    return 0;
}
