int noOfWays[37];
bool flag = true;

int Solution::climbStairs(int A)
{
    if (flag)
    {
        memset(noOfWays, 0, sizeof(noOfWays));
        noOfWays[0] = 1;
        noOfWays[1] = 1;
        noOfWays[2] = 2;
        for (int i = 3; i < 37; i++)
        {
            noOfWays[i] = noOfWays[i - 1] + noOfWays[i - 2];
        }

        flag = false;
    }
    return noOfWays[A];
}
