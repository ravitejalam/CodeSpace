#include <bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    set<int> rows,cols;
    for ( int i =0 ; i< A.size(); i++){
        for ( int j=0 ; j< A[i].size(); j++){
            if(A[i][j] == 0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    for(int row: rows){
        for( int col=0 ; col < A[row].size();col++){
            A[row][col] = 0;
        }
    }
    
    for(int col: cols){
        for( int row=0; row < A.size();row++){
            A[row][col] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> A = {{1, 0, 1}, {1, 1, 1}, {1, 1, 1}};
    setZeroes(A);
    return 0;
}
