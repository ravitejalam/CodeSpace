#include <bits/stdc++.h>

using namespace std;

vector<int> subUnsort(vector<int> &A) {
    int leftCount = 0;
    for (int i = leftCount+1; i < A.size() && A[i]>=A[i-1]; i++)
        leftCount++;
    int rightCount = A.size()-1;
    for (int i = rightCount-1; i >= 0 && A[i]<=A[i+1]; i--)
        rightCount--;
    if(rightCount<leftCount)
        return {-1};
    int mini = *min_element(A.begin()+leftCount,A.begin()+rightCount+1);
    int maxi = *max_element(A.begin()+leftCount,A.begin()+rightCount+1);
    for (int i = rightCount+1; i < A.size() && A[i] < maxi ; i++)
        rightCount++;
    for (int i = leftCount-1; i >=0 && A[i] > mini ; i--)
        leftCount--;
    return {leftCount,rightCount};
}
