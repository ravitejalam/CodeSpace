#define mod 10003

int noOfWays[100001];
bool flag = true;

int Solution::solve(int A)
{
    if (flag)
    {
        noOfWays[0] = 0;
        noOfWays[1] = 1;
        noOfWays[2] = 2;
        for (int i = 3; i < 100001; i++)
            noOfWays[i] = (noOfWays[i - 1] + (noOfWays[i - 2] * (i - 1)) % mod) % mod;
        flag = false;
    }
    return noOfWays[A];
}
