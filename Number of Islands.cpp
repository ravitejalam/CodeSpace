#include "bits/stdc++.h"

using namespace std;

int traverseIsland(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;
    if (grid[i][j] == '1'){
        grid[i][j] = '-';
        return 1 + traverseIsland(grid, i + 1, j) + traverseIsland(grid, i, j + 1)
               + traverseIsland(grid, i - 1, j) + traverseIsland(grid, i, j - 1);
    }
    return 0;
}

int numIslands(vector<vector<char>> &grid) {
    int largest_island_size = 0;
    int islands_count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1'){
                islands_count+=1;
                largest_island_size = max(largest_island_size, traverseIsland(grid, i, j));
            }
        }
    }
    for (auto & i : grid) {
        for (char & j : i) {
            if(j  == '-') j = '1';
        }
    }
    return islands_count;
}

int main() {
    vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };
    cout << numIslands(grid);
    return 0;
}
