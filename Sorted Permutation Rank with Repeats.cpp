#define M 1000003

long long int factorial(long long int n)
{
    if(n > 1)
        return (n* factorial(n - 1))%M;
    else
        return 1;
}

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;
    while (y > 0)
    {
        x %= p;
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long int modInverse(long long int n, long long int p)
{
    return power(n, p - 2, p);
}

int Solution::findRank(string A) {
    long long int rank = 1, s = A.size();
    for (int i = 0; i < s; i++)
    {
        long long int count = 0;
        for (int j = i + 1; j < s; j++)
        {
            A[i] > A[j] ? count++ : true;
        }
        long long int fact_d = 1;
        vector<int> d_count(52, 0);

        for (int j = i; j < s; j++)
        {
            if ((int(A[j]) >= 'A') && int(A[j]) <= 'Z')
                d_count[int(A[j]) - 'A'] += 1;
            else
                d_count[int(A[j]) - 'a' + 26] += 1;
        }
        for (int ele : d_count)
            fact_d = (fact_d*factorial(ele))%M;
        
        count%=M;
        fact_d = modInverse(fact_d,M);
        long long int tmp = factorial(s - i - 1);
        tmp = (tmp * fact_d)%M;
        tmp = (tmp*count)%M;
        rank = (rank +tmp)%M;
        
        // rank = (rank + ((count * factorial(s - i - 1)) / fact_d)) % 1000003;
    }
    return rank;
}