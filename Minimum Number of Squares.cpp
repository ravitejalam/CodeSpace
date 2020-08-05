int minSq[100001];
bool flag = true;

int Solution::countMinSquares(int A)
{
    if (flag)
    {
        minSq[0] = 0;
        for (int i = 1; i < 100001; i++)
        {
            minSq[i] = i;
            for (int j = 0; j * j <= i; j++)
            {
                minSq[i] = min(minSq[i], 1 + minSq[i - j * j]);
            }
        }

        flag = false;
    }
    return minSq[A];
}