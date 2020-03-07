#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > generateMatrix(int A) {
    vector<vector<int> > spiral( A , vector<int> (A));
    int value = 1,n = A;
    int minCol = 0;
    int maxCol = n-1;
    int minRow = 0;
    int maxRow = n-1;
     
    while (value <= n*n)
    {
        for (int i = minCol; i <= maxCol; i++)
        {
            spiral[minRow][i] = value;
            value++;
        }
         
        for (int i = minRow+1; i <= maxRow; i++) 
        { 
            spiral[i][maxCol] = value; 
            value++; 
        } 
         
        for (int i = maxCol-1; i >= minCol; i--)
        {
            spiral[maxRow][i] = value;
            value++;
        }
         
        for (int i = maxRow-1; i >= minRow+1; i--) 
        {
            spiral[i][minCol] = value;
            value++;
        }
         
        minCol++;
        minRow++;
        maxCol--;
        maxRow--;
    }
    return spiral;
}

int main()
{
    vector<vector<int> > B = generateMatrix(3);
    return 0;
}