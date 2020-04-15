#include <bits/stdc++.h>

using namespace std;

#define M 1000000007

void multiply(vector<vector<long long int>> &resultMatrix, vector<vector<long long int>> &Matrix)
{
    long long int sum11 = (resultMatrix[0][0] * Matrix[0][0]) % M;
    long long int sum12 = (resultMatrix[0][1] * Matrix[1][0]) % M;
    long long int sum21 = (resultMatrix[0][0] * Matrix[0][1]) % M;
    long long int sum22 = (resultMatrix[0][1] * Matrix[1][1]) % M;
    long long int sum31 = (resultMatrix[1][0] * Matrix[0][0]) % M;
    long long int sum32 = (resultMatrix[1][1] * Matrix[1][0]) % M;
    long long int sum41 = (resultMatrix[1][0] * Matrix[0][1]) % M;
    long long int sum42 = (resultMatrix[1][1] * Matrix[1][1]) % M;
    resultMatrix[0][0] = (sum11 + sum12) % M;
    resultMatrix[0][1] = (sum21 + sum22) % M;
    resultMatrix[1][0] = (sum31 + sum32) % M;
    resultMatrix[1][1] = (sum41 + sum42) % M;
}

long long int fib(int N)
{
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;
    vector<vector<long long int>> exp = {{1, 1}, {1, 0}};
    vector<vector<long long int>> ans = {{1, 0}, {0, 1}};
    N--;
    while (N > 0)
    {
        if (N % 2 == 1)
        {
            N--;
            multiply(ans, exp);
        }
        else
        {
            N /= 2;
            multiply(exp, exp);
        }
    }

    return ans[0][0];
}

int solve(int A, int B)
{
    A++;
    B += 2;
    long long int fibA = fib(A);
    long long int fibB = fib(B);
    return (fibB - fibA + M)%M;
}