char getSimilarOpenBrace(char c)
{
    char ans;
    switch (c)
    {
    case ')':
        ans = '(';
        break;
    case ']':
        ans = '[';
        break;
    case '}':
        ans = '{';
        break;
    case '(':
        ans = ')';
        break;
    case '[':
        ans = ']';
        break;
    case '{':
        ans = '}';
        break;
    default:
        ans = ' ';
        break;
    }
    return ans;
}

int Solution::LBSlength(const string A)
{
    int dp[A.size() + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < A.length(); i++)
    {
        if (A[i] == ')' || A[i] == ']' || A[i] == '}')
        {
            if (A[i] == getSimilarOpenBrace(A[i - 1]))
            {
                dp[i] = (i - 2) >= 0 ? (dp[i - 2] + 2) : 2;
            }
            else
            {
                if (i - dp[i - 1] - 1 >= 0 && (A[i] == getSimilarOpenBrace(A[i - dp[i - 1] - 1])))
                {
                    dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0);
                }
            }
        }
    }
    return *max_element(dp, dp + A.size() + 1);
}