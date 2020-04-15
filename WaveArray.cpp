#include <bits/stdc++.h>

using namespace std;

vector<int> wave(vector<int> &A) {
    sort(A.begin(),A.end());
    int tmp;
    for(int i = 1 ; i< A.size();i+=2){
        tmp = A[i];
        A[i]=A[i-1];
        A[i-1]=tmp;
    }
    return A;
}
