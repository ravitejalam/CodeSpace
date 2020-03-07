#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &A) {
    int s = A.size();
    bool flag = true;
    for( int i = s-1 ; i >= 0 ; i-- ){
        if(A[i] == 9){
            A[i] = 0;
            continue;
        }
        A[i] += 1;
        flag = false;
        break;
    }
    if(flag){
        A.insert(A.begin(),1);
    }
    while(A[0]==0){
        A.erase(A.begin());
    }
    return A;
}

int main()
{
    vector<int> A = {1, 2, 4};
    vector<int> B = plusOne(A);
    return 0;
}
