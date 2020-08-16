#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<vector<int>> &A)
{
    vector<pair<int, char>> checkpoints;
    for (int i = 0; i < A.size(); i++)
    {
        checkpoints.push_back(make_pair(A[i][0], 's'));
        checkpoints.push_back(make_pair(A[i][1], 'e'));
    }
    sort(checkpoints.begin(), checkpoints.end());
    int rooms_req = 0, curr_rooms_req = 0;
    for (int i = 0; i < checkpoints.size(); i++)
    {
        curr_rooms_req += checkpoints[i].second == 's' ? 1 : -1;
        rooms_req = max(rooms_req, curr_rooms_req);
    }
    return rooms_req;
}
