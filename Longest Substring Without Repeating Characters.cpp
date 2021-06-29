#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string A)
{
    unordered_set<char> s;
    int left = 0;
    int right = 0;
    int ans = 0;
    while (right < A.size())
    {
        if (s.find(A[right]) == s.end())
            s.insert(A[right]);
        else
        {
            while (A[left]!=A[right])
            {
                s.erase(A[left]);
                left++;
            }
            left++;
        }
        right++;
        ans = max(ans,right-left);
    }
    return ans;
}
