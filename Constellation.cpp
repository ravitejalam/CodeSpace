#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len;
    cin >> len;
    string first, second, third;
    getline(cin, first);
    cout << first << endl;
    getline(cin, second);
    cout << second << endl;
    getline(cin, third);
    cout << third << endl;
    first.erase(remove(first.begin(), first.end(), ' '), first.end());
    second.erase(remove(second.begin(), second.end(), ' '), second.end());
    third.erase(remove(third.begin(), third.end(), ' '), third.end());
    int curr = 0;
    string ans = "";
    while (curr < len)
    {
        if (first[curr] == '#')
        {
            ans += "#";
            curr++;
        }
        else if (first[curr] == '.' && second[curr] == '.' && third[curr] == '.')
            curr++;
        else
        {
            if (first[curr] == '.' && first[curr + 1] == '*' && first[curr + 2] == '.')
                ans += "A";
            else if (second[curr] == '.' && second[curr + 1] == '*' && second[curr + 2] == '.')
                ans += "I";
            else if (first[curr + 1] == '*' && second[curr + 1] == '.' && third[curr + 1] == '*')
                ans += "O";
            else if (first[curr + 1] == '.' && second[curr + 1] == '.' && third[curr + 1] == '*')
                ans += "U";
            else
                ans += "E";
            curr += 3;
        }
    }
    cout << ans;
    return 0;
}
