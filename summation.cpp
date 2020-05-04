#define M 1000000007

long long int power(long long int base,long long int exp,long long int mod){
    long long int res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}

int Solution::solve(int A) {
    if(A<2)
        return 0;
    long long int ans = (A*(A-1))%M;
    long long int pow = power(3,A-2,M);
    return (ans*pow)%M;
}