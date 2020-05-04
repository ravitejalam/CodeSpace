void buildZ(string str, int Z[])
{
    int n = str.length();
    int L, R, k;
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            k = i - L;
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
            else
            {
                L = i;
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
    Z[0] = n;
}

int Solution::solve(string A) {
    string concat = A;
    reverse(A.begin(),A.end());
    concat += "#" + A;
    int l = concat.length();
    int Z[l];
    buildZ(concat,Z);
    for (int i = A.size()+1; i < l; i++)
    {
        if(l-i==Z[i])
            return A.size()-Z[i];
    }
    return A.size()-1;
}