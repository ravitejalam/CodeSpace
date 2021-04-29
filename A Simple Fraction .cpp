#include "bits/stdc++.h"

using namespace std;

// Convert it into a decimal. If the fractional part is repeating, enclose the repeating part in parentheses.
string fractionToDecimal(int numerator, int denominator) {
    string before_decimal = to_string(numerator / denominator);
    numerator %= denominator;
    string after_decimal;
    unordered_map<int, int> rem_map;
    while (numerator) {
        if (rem_map.find(numerator) != rem_map.end()) {
            after_decimal.push_back(')');
            after_decimal.insert(after_decimal.begin() + rem_map[numerator], '(');
            break;
        }
        rem_map[numerator] = after_decimal.length();
        numerator *= 10;
        after_decimal += to_string(numerator / denominator);
        numerator %= denominator;
    }
    return before_decimal + (after_decimal.length() ? "." + after_decimal : "");
}

int main() {
    cout << fractionToDecimal(1, 3) << endl;
    cout << fractionToDecimal(3, 3) << endl;
    cout << fractionToDecimal(5, 2) << endl;
    cout << fractionToDecimal(22, 7) << endl;
    return 0;
}
