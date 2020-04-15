#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &A) {
    int positivePos = 0, negativePos = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (i & 1)
        {
            //setPositive();
            if (A[i]<0)
            {
                positivePos=i;
                for (int j = positivePos; j < A.size() && A[positivePos]<0; j++)
                    positivePos++;
                if(positivePos==A.size())
                    break;
                // swap(A[i],A[positivePos]);
                for (int x = positivePos; x > i; x--)
                    swap(A[x],A[x-1]);
                positivePos++;
            }
        }
        else
        {
            //setNegative();
            if(A[i]>=0){
                negativePos=i;
                for (int j = negativePos; j < A.size() && A[negativePos]>=0; j++)
                    negativePos++;
                if(negativePos==A.size())
                    break;
                // swap(A[i],A[negativePos]);
                for (int x = negativePos; x > i; x--)
                    swap(A[x],A[x-1]);
                negativePos++;
            }
        }
    }
    return A;
}
