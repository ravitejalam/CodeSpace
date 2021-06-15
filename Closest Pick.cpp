#include "bits/stdc++.h"

using namespace std;

int minDistances(unordered_set<int> &purchased, int num) {
    int x = INT_MAX;
    for (int v:purchased) {
        x = min(x, abs(num - v));
    }
    return x;
}

double probability(unordered_set<int> &purchased, int k, int i, int j) {
    int chance = 0;
    for (int a = 0; a < k; ++a) {
        if (minDistances(purchased, a + 1) < min(abs(a + 1 - i), abs(a + 1 - j)))
            continue;
        else if (minDistances(purchased, a + 1) == min(abs(a + 1 - i), abs(a + 1 - j)))
            continue;
        chance += 1;
    }
    return (1.0 * chance / k);
}

double getProb(unordered_set<int> &purchased, int k) {
    double prob = 0.0;
    if (purchased.size() + 1 == k) {
        prob = 1.0 / k;
        return prob;
    }
    int front = 1;
    int back = k;
    while (front <= back) {
        if (purchased.find(front) != purchased.end()) {
            front += 1;
            continue;
        }
        if (purchased.find(back) != purchased.end()) {
            back -= 1;
            continue;
        };
        prob = max(prob, probability(purchased, k, front, back));
        front+=1;
        back-=1;
    }
    return prob;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        unordered_set<int> purchased;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            purchased.insert(x);
        }
        double ans = getProb(purchased, k);
        if (ans == 0.0)
            cout << "Case #" << i + 1 << ": 0.0" << endl;
        else
            cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}
