#include "bits/stdc++.h"

using namespace std;

int reversort(vector<int> &list, int L) {
    int cost = 0;
    for (int i = 0; i < L - 1; ++i) {
        int j = i + distance(list.begin() + i, min_element(list.begin() + i, list.end()));
        reverse(list.begin() + i, list.begin() + j + 1);
        cost += j - i + 1;
    }
    return cost;
}

int main() {
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        int L;
        cin >> L;
        vector<int> A(L);
        for (int e = 0; e < L; ++e) {
            cin >> A[e];
        }
        cout << "Case " << "#" << c+1 << ": " << reversort(A, L) << endl;
    }
    return 0;
}
