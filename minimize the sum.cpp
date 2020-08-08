#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int input;
    int n, k;
    cin >> n;
    cin >> k;
    while (cin >> input)
        pq.push(input);
    for (int i = 0; i < k; i++)
    {
        int temp = pq.top() / 2;
        pq.pop();
        pq.push(temp);
    }
    int s = 0;
    while (!pq.empty())
    {
        s += pq.top();
        pq.pop();
    }
    cout << s;
    return 0;
}