#include <bits/stdc++.h>

using namespace std;

int solve(int A) {
    int c = 1,s = ceil(sqrt(A)),z=1;
    for(int i = 2;(i*(i-1)) < (2*A);i++){
        if(A%i==0 && i%2==1){
            c++;
        }
        else if (A%i==i/2 && i%2==0)
        {
            c++;
        }
    }
    return c;
}

int main()
{
    cout << solve(9);
    return 0;
}