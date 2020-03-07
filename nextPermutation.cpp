#include <bits/stdc++.h>

using namespace std;

vector<int> nextPermutation(vector<int> &A) {
    int s = A.size(),i = s-2;
    
    if (s<2){
        return A;
    }
    bool flag = true;
    while (i>=0)
    {
        if (A[i] < A[i+1]){
            int mini = INT_MAX, mini_i;
            for( int j = i+1 ; j < s ; j++){
                if(mini >= A[j] && A[j] > A[i]){
                    mini = A[j];
                    mini_i = j;
                }
            }
            int tmp = A[i];
            A[i] = mini;
            A[mini_i] = tmp;
            sort(A.begin()+(i+1),A.end());
            flag = false;
            break;
        }
        i--;
    }
    if(flag){
        reverse(A.begin(), A.end());
    }
    return A;
}


int main()
{
    vector<int> B = {1, 2, 3};
    nextPermutation(B);
    return 0;
}
