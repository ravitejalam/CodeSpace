#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    for (int i = 0; i < n/2; i++)
    {
        for (int col = i; col < n-i-1; col++)
        {
            int tmp = A[i][col];
            A[i][col] = A[n-col-1][i];
            A[n-col-1][i] = A[n-i-1][n-col-1];
            A[n-i-1][n-col-1] = A[col][n-i-1];
            A[col][n-i-1] = tmp;
        }
    }    
}

void printMatrix(vector<vector<int> > A){
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;        
    }
    
}

int main()
{
    vector<vector<int>> A = {{1, 2, 3,4},{5, 6,7,8},{9,10,11,12},{13,14,15,16}};
    printMatrix(A);
    rotate(A);
    printMatrix(A);
    return 0;
}
