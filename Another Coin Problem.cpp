long long unsigned int values[14];
bool flag = true;

int Solution::solve(int A)
{
    if (flag)
    {
        int value = 1;
        for (int i = 0; i < 14; i++)
        {
            values[i] = value;
            value *= 5;
        }
    }
    int i = 13;
    int coins = 0;
    while (A)
    {
        if (A >= values[i])
        {
            A -= values[i];
            coins++;
        }
        else
        {
            i--;
        }
    }
    return coins;
}