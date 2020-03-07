#include <bits/stdc++.h>

using namespace std;

// Definition for an interval.
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start);
}

bool compareIntervalEnd(Interval i1, Interval i2) 
{ 
    return (i1.end < i2.end);
}

vector<Interval> merge(vector<Interval> &A) {
    // sort(A.begin(), A.end(), compareIntervalEnd);
    sort(A.begin(), A.end(), compareInterval);
    int s = A.size();
    int first = 0, second = 1;
    for (int i = 1; i < s; i++)
    {
        if (A[second].start <= A[first].end)
        {
            A[first].end = max(A[first].end, A[second].end);
            second++;
        }
        else
        {
            first++;
            Interval tmp = A[first];
            A[first] = A[second];
            A[second] = tmp;
            second++;
        }
    }
    A.erase(A.begin() + first + 1, A.end());
    return A;
}


int main()
{
    vector<Interval> A = {{1, 10}, {2, 9}, {3, 8}, {4, 7}, {5, 6}, {6, 6}};
    vector<Interval> B = merge(A);
    return 0;
}
