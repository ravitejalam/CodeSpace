#include <bits/stdc++.h>

using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// Note what is the net change in number of 1s in string S when we flip bits of string S.
// Say it has A 0s and B 1s. Eventually, there are B 0s and A 1s.

// So, number of 1s increase by A - B. We want to choose a subarray which maximises this.
// Note, if we change 1s to -1, then sum of values will give us A - B.
// Then, we have to find a subarray with maximum sum, which can be done via Kadane’s Algorithm.

vector<int> flip(string A) {
    int s = A.size();
    int max_i = -1, max_j = -1,max_flips = 0;
    int maxi = 0;
    int cost = 0;
    for (int i = 0; i < s; i++)
    {
        if(A[i]=='0'){
            cost++;
        }
        else
        {
            cost--;
        }
        if(cost<0){
            maxi = i+1;
            cost = 0;
        }else if(cost>max_flips)
        {
            max_flips = cost;
            max_i = maxi;
            max_j = i;            
        }
    }
    vector<int> res;
    if(max_i != -1)
    {
        res.push_back(max_i+1);
        res.push_back(max_j+1);
    }
    return res;
}

int main()
{
    vector<int> A = flip("1101");
    cout << A[0] << " " << A[1] << endl;
    return 0;
}