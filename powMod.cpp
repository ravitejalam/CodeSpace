#include <bits/stdc++.h>

using namespace std;

int pow_mod(int a,int b,int m){
    if(b%2 == 0){
        return pow_mod((a*a)%m,b/2,m);
    }
    return pow_mod((a*a)%m,b/2,m) * a;
}

int main()
{
    cout << pow_mod(2,18,10);
    return 0;
}
