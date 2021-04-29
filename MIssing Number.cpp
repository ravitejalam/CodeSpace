#include "bits/stdc++.h"

using namespace std;

int MissingNumber(vector<int> &array, int n) {
    int array_xor = 0;
    int complete_xor = 0;
    for (int i = 0; i < n; ++i) {
        if (i < array.size()) array_xor ^= array[i];
        complete_xor ^= (i + 1);
    }
    return complete_xor ^ array_xor;
}

int main() {
    vector<int> a = {1,2,3,4,5,6,7,8,10};
    cout << MissingNumber(a,10);
    return 0;
}
