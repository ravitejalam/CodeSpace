string Solution::solve(string A) {
    int x = 0;
    bool flag = true;
    while (A[A.length()-1] == ' ')
    {   
        A.erase(A.length()-1);
    }
    while (x <A.length())
    {
        if(A[x] == ' '){
            if(flag){
                flag = true;
                A.erase(A.begin()+x);
            }
            else
            {
                flag = true;
                x++;
            }
        }
        else{
            x++;
            flag = false;      
        }
    }
    reverse(A.begin(), A.end());
    int left = 0;
    int right = 0;
    int l = A.length();
    while (left < l && right < l)
    {
        if (right == l - 1)
        {
            reverse(A.begin() + left, A.begin() + right + 1);
            break;
        }
        else if (A[right] == ' ')
        {
            reverse(A.begin() + left, A.begin() + right);
            left = right + 1;
            right = right + 1;
        }
        else
        {
            right++;
        }
    }
    return A;
}
