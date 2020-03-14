#include <bits/stdc++.h>

using namespace std;

string convertToTitle(int A) {
    string ans = "";
    while (A>0)
    {
        A--;
        ans+=((A)%26+'A');
        A/=26;
    }
    ans,reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    cout << convertToTitle(943566);
    return 0;
}
