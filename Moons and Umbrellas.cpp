#include "bits/stdc++.h"

using namespace std;

int paintingCost(string s, int x, int y) {
    int cost = 0;
    char prev = '^';
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'C') {
            if (prev == 'J')
                cost += y;
            prev = 'C';
        } else if (s[i] == 'J') {
            if (prev == 'C')
                cost += x;
            prev = 'J';
        }
    }
    return cost;
}

int main() {
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        int X, Y;
        string S;
        cin >> X;
        cin >> Y;
        cin >> S;
        int cost = paintingCost(S, X, Y);
        cout << "Case " << "#" << c + 1 << ": " << cost << endl;
    }
    return 0;
}
