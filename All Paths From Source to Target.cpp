#include <bits/stdc++.h>

using namespace std;

void traverse(int start, vector<vector<int>> &graph, vector<vector<int>> &ans, unordered_set<int> &visited, vector<int> &curr)
{
    curr.push_back(start);
    visited.insert(start);
    if (start == graph.size() - 1)
    {
        ans.push_back(curr);
    }
    else
    {
        for (int next = 0; next < graph[start].size(); next++)
        {
            if (visited.find(graph[start][next]) == visited.end())
                traverse(graph[start][next], graph, ans, visited, curr);
        }
    }
    visited.erase(start);
    curr.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> ans;
    vector<int> curr;
    unordered_set<int> visited;
    traverse(0, graph, ans, visited, curr);
    return ans;
}

int main()
{
    vector<vector<int>> g = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> result = allPathsSourceTarget(g);
    return 0;
}
