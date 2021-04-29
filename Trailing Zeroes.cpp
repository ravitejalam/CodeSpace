#include "bits/stdc++.h"

using namespace std;

// number of trailing zeroes in N!
int trailingZeroes(int N) {
    int zeros = 0;
    int five_power = 5;
    while (five_power <= N) {
        zeros += N / five_power;
        five_power *= 5;
    }
    return zeros;
}

int main() {
    cout << trailingZeroes(384);
    return 0;
}
