#include "bits/stdc++.h"

using namespace std;

void getList(int i, vector<int> &list, int len, int cost) {
    if (i >= len - 1)
        return;
    int level_cost = len - i-1;
    bool flag = cost >= level_cost;
    cost -= flag ? level_cost : 0;
    getList(i + 1, list, len, cost);
    if (flag)
        reverse(list.begin() + i, list.end());
}

string reversort(int len, int cost) {
    int max_cost = ((len * (len + 1)) / 2) - 1;
    if (cost > max_cost || cost < len - 1)
        return "IMPOSSIBLE";
    vector<int> a(len);
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
    }
    getList(0, a, len, cost-len+1);
    ostringstream oss;
    copy(a.begin(), a.end() - 1, ostream_iterator<int>(oss, " "));
    oss << a.back();
    return oss.str();
}

int main() {
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        int L, C;
        cin >> L;
        cin >> C;
        cout << "Case " << "#" << c + 1 << ": " << reversort(L, C) << endl;
    }
    return 0;
}
