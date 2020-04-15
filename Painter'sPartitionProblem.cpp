#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &wall,int maxUnits,int painters){
    int sum =0,paintersSet=0;
    for (int i = 0; i <= wall.size(); i++)
    {
        if(i==wall.size() and sum<=maxUnits){
            paintersSet++;
        }
        else if(sum+wall[i]<=maxUnits){
            sum+=wall[i];
        }
        else{
            sum=wall[i];
            paintersSet++;
        }
    }
    return paintersSet<=painters;
}

int paint(int A, int B, vector<int> &C)
{
    unsigned long long int left = *max_element(C.begin(),C.end()), right = 0, mid, ans;
    for (int i = 0; i < C.size(); i++)
    {
        right += C[i];
    }

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (isPossible(C, mid,A))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return (ans * B) % 10000003;
}