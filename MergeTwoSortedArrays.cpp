#include <bits/stdc++.h>

using namespace std;

vector<int> solve(const vector<int> &A, const vector<int> &B) {
    vector<int> ans(A.size() + B.size());
    int a = 0, b = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if(a>=A.size()){
            ans[i]=B[b];
            b++;
            continue;
        }
        if(b>=B.size()){
            ans[i]=A[a];
            a++;
            continue;
        }
        if(A[a]<=B[b]){
            ans[i]=A[a];
            a++;
        }
        else
        {
            ans[i]=B[b];
            b++;
        }
    }
    return ans;
}
