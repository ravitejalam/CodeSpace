#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> A, int e)
{
    int s = A.size(), left = 0, right = s - 1, mid, index = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] == e)
        {
            index = mid;
            break;
        }
        else if (A[mid] < e)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return index;
}