int DivisibilityByEleven(int num)
{
    vector<int> digits;
    while (num > 0)
    {
        digits.push_back(num % 10);
        num /= 10;
    }
    reverse(digits.begin(), digits.end());
    bool flag = true;
    int ans = 0;
    for (int i = 1; i < digits.size(); i++)
    {
        digits[i] = digits[i - 1] + (flag ? -1 : 1) * digits[i];
        flag = !flag;
    }
    for (int i = 0; i < digits.size(); i++)
    {
        for (int j = i; j < digits.size(); j++)
        {
            if ((digits[j] - (i > 0 ? digits[i-1] : 0))%11 == 0){
                ans+=1;
            }
        }
    }
    return ans;
}