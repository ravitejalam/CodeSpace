#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, int B)
{
    int count=0, bad=0, good=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(A[i]<=B)
            good++;
    }
    for(int i=0;i<good;i++){
        if(A[i]>B)
            bad++;
    }
    count=bad;
    for(int i=good;i<n;i++){
        if(A[i]>B)
            bad++;
        if(A[i-good]>B)
            bad--;
        count=std::min(bad, count);
    }
    return count;
}

int main()
{
    vector<int> A = {1, 12, 10, 3, 14, 10, 5};
    int B = 8;
    cout << solve(A, B);
    return 0;
}
