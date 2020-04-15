#include <bits/stdc++.h>

using namespace std;

int findIndexOfPartner(map<int, int> &positions, vector<vector<int>> &pairs, int element)
{
    for (int i = 0; i < pairs.size(); i++)
    {
        if (pairs[i][0] == element)
        {
            return positions[pairs[i][1]];
        }
        else if (pairs[i][1] == element)
        {
            return positions[pairs[i][0]];
        }
    }
}

void getTogether(int noOfPairs, vector<int> &seats, vector<vector<int>> &pairs, int index, int &minSwaps, int currentSwaps, map<int, int> &positions)
{
    if (index == 2 * noOfPairs)
    {
        minSwaps = min(minSwaps, currentSwaps);
        return;
    }

    int pair_index_1 = index;
    int pair_ele_1 = seats[pair_index_1];

    int pair_index_2 = findIndexOfPartner(positions, pairs, pair_ele_1);
    int pair_ele_2 = seats[pair_index_2];

    if (pair_index_2 != pair_index_1 + 1)
    {
        int other_index_2 = index + 1;
        int other_ele_2 = seats[other_index_2];

        int other_index_1 = findIndexOfPartner(positions, pairs, other_ele_2);
        int other_ele_1 = seats[other_index_1];

        swap(seats[pair_index_2], seats[other_index_2]);

        positions[seats[pair_index_2]] = pair_index_2;
        positions[seats[other_index_1]] = other_index_1;

        currentSwaps++;
    }

    getTogether(noOfPairs, seats, pairs, index + 2, minSwaps, currentSwaps, positions);
}

int solve(int A, vector<int> &B, vector<vector<int>> &C)
{
    int minSwaps = INT_MAX;
    map<int, int> positions;
    for (int i = 0; i < B.size(); i++)
    {
        positions.insert(pair<int, int>(B[i], i));
    }
    getTogether(A, B, C, 0, minSwaps, 0, positions);
    return minSwaps;
}