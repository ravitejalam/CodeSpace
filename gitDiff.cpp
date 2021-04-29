#include "bits/stdc++.h"

using namespace std;

void displayDiff(string before, string after, vector<vector<int>> &dp) {
    int old_len = before.length();
    int new_len = after.length();
    while (old_len && new_len) {
        if (before[old_len - 1] == after[new_len - 1]) {
            cout << before[old_len - 1] << endl;
            old_len -= 1;
            new_len -= 1;
        } else {
            if (dp[new_len - 1][old_len] < dp[new_len][old_len - 1]) {
                cout << "+" << after[new_len - 1] << endl;
                new_len -= 1;
            } else {
                cout << "-" << before[old_len - 1] << endl;
                old_len -= 1;
            }
        }
    }
    while (old_len) {
        old_len -= 1;
        cout << "-" << before[old_len] << endl;
    }
    while (new_len) {
        new_len -= 1;
        cout << "+" << after[new_len] << endl;
    }
}

int gitDiff(string before, string after) {
    int old_len = before.length();
    int new_len = after.length();
//    int dp[new_len + 1][old_len + 1];
//    memset(dp, 0, sizeof dp);
    vector<vector<int>> dp(new_len + 1, vector<int>(old_len + 1, 0));
    for (int i = 0; i <= new_len; ++i) {
        for (int j = 0; j <= old_len; ++j) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else {
                if (after[i - 1] == before[j - 1])
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                else
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1] + 2);
            }
        }
    }
    displayDiff(before, after, dp);
    return dp[after.length()][before.length()];
}

int main() {
    string before = "vite";
    string after = "raviteja";
    cout << gitDiff(before, after) << endl;
    return 0;
}
