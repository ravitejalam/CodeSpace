#define Mod 10000003

int Solution::seats(string A)
{
    int start = 0;
    int end = A.size() - 1;
    while (start <= end && A[start] == '.')
        start++;
    while (start <= end && A[end] == '.')
        end--;
    int leftPersons = 0;
    int rightPersons = 0;
    for (int i = start; i <= end; i++)
        if (A[i] == 'x')
            rightPersons++;
    int minCost = 0;
    for (int i = start; i <= end; i++)
    {
        if (A[i] == 'x')
        {
            leftPersons++;
            rightPersons--;
        }
        else if (leftPersons < rightPersons)
            minCost = (minCost + leftPersons) % Mod;
        else
            minCost = (minCost + rightPersons) % Mod;
    }
    return minCost;
}