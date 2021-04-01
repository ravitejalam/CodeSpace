#include "bits/stdc++.h"

using namespace std;

bool buddyStrings(string a, string b) {
    if (a.length() != b.length()) return false;
    vector<int> diff;
    set<char> s;
    for (int i = 0; i < b.length(); ++i) {
        if (a[i] != b[i]) diff.push_back(i);
        if (diff.size() > 2) return false;
        s.insert(a[i]);
    }
    if (diff.size() == 2 && a[diff[0]] == b[diff[1]] && a[diff[1]] == b[diff[0]]) return true;
    if (diff.empty() && s.size() < a.length()) return true;
    return false;
}