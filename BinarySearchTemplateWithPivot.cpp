#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> A, int e)
{
    int s = A.size(), left = 0, right = s - 1, mid = 0, index = -1, pivot = 0;
    for (int i = 1; i < s; i++)
    {
        if (A[i] < A[i - 1])
        {
            pivot = i;
            break;
        }
    }
    if (A[0] == e)
    {
        return 0;
    }
    else if (A[0] > e)
    {
        left = pivot;
        right = s - 1;
    }
    else
    {
        left = mid + 1;
        right = (pivot + s - 1) % s;
    }

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

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 2, 3, 4, 5};
    cout << binarySearch(A, 1);
    return 0;
}
