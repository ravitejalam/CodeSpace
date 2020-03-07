#include <bits/stdc++.h>

using namespace std;

int countDigitOne(int A) 
{ 
    int countr = 0; 
    for (int i = 1; i <= A; i *= 10) { 
        int divider = i * 10; 
        countr += (A / divider) * i + min(max(A % divider - i + 1, 0), i); 
    } 
    return countr;
} 

int main()
{
    cout << countDigitOne(232);
    return 0;
}
