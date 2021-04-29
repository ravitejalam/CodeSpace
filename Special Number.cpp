#include <bits/stdc++.h>

using namespace std;

int getLeftMax(int a, int b, int num) {
    int A = a;
    while (A * a <= num) A *= a;
    int B = b;
    int leftMax = 0;
    while (A >= a) {
        if (A + B > num) {
            A /= a;
        } else {
            leftMax = max(leftMax, A + B);
            B *= b;
        }
    }
    return leftMax;
}

int getRightMin(int a, int b, int num) {
    int A = a;
    while (A < num) A *= a;
    int B = b;
    int rightMin = INT_MAX;
    while (A >= a) {
        if (A + B < num) {
            B *= b;
        } else {
            rightMin = min(rightMin, A + B);
            A /= a;
        }
    }
    return rightMin;
}

int solve(int num, int decCost, int incCost) {
    vector<int> costs;
    vector<int> combinations = {3, 5, 7, 3};
    for (int i = 0; i < 3; ++i) {
        int tmp = getLeftMax(combinations[i], combinations[i + 1], num);
        if (tmp) costs.push_back((num - tmp) * decCost);
        costs.push_back((getRightMin(combinations[i], combinations[i + 1], num) - num) * incCost);
    }
    return *min_element(costs.begin(), costs.end());
}

int main() {
    cout << solve(53, 8, 7);
    return 0;
}
