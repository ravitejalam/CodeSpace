#include <bits/stdc++.h>

using namespace std;

long long int value(long long int base, long long int len){
    long long int res  = 0;
    for (long long int i = 0; i < len; i++)
    {
        res +=pow(base,i);
    }
    return res;
}

long long int checkPossibility(long long int N, long long int len){
    long long int left = 2,right = N-1,mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        long long int val = value(mid,len);
        if (val==N)
        {
            return mid;
        }
        else if(val > N){
            right = mid -1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

string solve(string A) {
    long long int N,ANS;
    stringstream ss(A);
    ss >> N;
    if(N > INT_MAX)
        return to_string(N-1);
    for (int i = 64; i > 0; i--)
    {
        ANS = checkPossibility(N,i);
        if(ANS!=-1){
            break;
        }
    }
    return to_string(ANS);
}