#include "bits/stdc++.h"

using namespace std;

bool isOrdered(long long int h, long long int m, long long int s) {
    return (m % (6 * 12 * 10000000000)) == s / 60 && (h % (30 * 12 * 10000000000)) == m / 12;
}

string getTime(long long int h, long long int m, long long int s) {
    string H = to_string(h / (30 * 12 * 10000000000));
    string M = to_string(m / (6 * 12 * 10000000000));
    string S = to_string(s / (6 * 12 * 10000000000));
    string N = to_string(s % (6 * 12 * 10000000000));
    return H + " " + M + " " + S + " " + N;
}

string solve(long long int A, long long int B, long long int C) {
    if (isOrdered(A, B, C)) return getTime(A, B, C);
    if (isOrdered(A, C, B)) return getTime(A, C, B);
    if (isOrdered(B, C, A)) return getTime(B, C, A);
    if (isOrdered(B, A, C)) return getTime(B, A, C);
    if (isOrdered(C, A, B)) return getTime(C, A, B);
    if (isOrdered(C, B, A)) return getTime(C, B, A);
}

int main() {
    int t;
    cin >> t;
    for (int c = 0; c < t; ++c) {
        long long int A, B, C;
        cin >> A >> B >> C;
        cout << "Case #" << c + 1 << ": " << solve(A, B, C) << endl;
    }
    return 0;
}
