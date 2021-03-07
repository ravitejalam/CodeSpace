#include <bits/stdc++.h>

using namespace std;

int calBeauty(unordered_map<char, int> &freq)
{
    int mini = INT_MAX;
    int maxi = 0;
    for (auto char_freq: freq)
    {
        mini = char_freq.second < mini ? char_freq.second : mini;
        maxi = char_freq.second > maxi ? char_freq.second : maxi;
    }
    return maxi - mini;
}

int beautySum(string s)
{
    // hash for freq
    unordered_map<char, int> freq = {};
    // final sum
    int ans = 0;
    // for string 1st to last -> i
    for (int i = 0; i < s.length(); i++)
    {
        // clear hash
        freq.clear();
        // for string i to last
        for (int j = i; j < s.length(); j++)
        {
            // update hash
            freq[s[j]]++;
            // sum += beauty
            ans += calBeauty(freq);
        }
    }
    // retunr final sum
    return ans;
}

int main()
{
    int ans = beautySum("aabcbaa");
    cout << ans;
    return 0;
}
