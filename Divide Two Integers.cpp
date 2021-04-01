#include "bits/stdc++.h"

using namespace std;

int divide(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX;
    if (dividend == INT_MIN) {
        if (divisor == 1)
            return INT_MIN;
        if (divisor == -1)
            return INT_MAX;
    }
    bool isNegative = (dividend < 0) ^(divisor < 0);
    long l_dividend = labs(dividend);
    long l_divisor = labs(divisor);
    int quotient = 0;
    while (l_dividend >= l_divisor) {
        long temp = l_divisor;
        int m = 1;
        while (temp << 1 <= l_dividend) {
            temp <<= 1;
            m <<= 1;
        }
        l_dividend -= temp;
        quotient += m;
    }
    if (isNegative)
        return 0 - quotient;
    return quotient;
}

int main() {
    cout << divide(-2147483648, 2);
    return 0;
}
