#include "bits/stdc++.h"

using namespace std;

int arrangements(int input1) {
    if (input1 == 1) return 0;
    if (input1 == 2) return 1;
    return (input1 - 1) * (arrangements(input1 - 1) + arrangements(input1 - 2));
}

int main() {
    cout << arrangements(4);
    return 0;
}
