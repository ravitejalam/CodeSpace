#include "bits/stdc++.h"

using namespace std;

int maxTickets(vector<int> tickets) {
    sort(tickets.begin(),tickets.end());
    if(tickets.empty())
        return 0;
    int ans = 1;
    int m = 1;
    for (int i = 1; i < tickets.size(); ++i) {
        int diff = tickets[i] - tickets[i-1];
        if (diff == 0 or diff == 1){
            m++;
            ans = max(m,ans);
        } else{
            m=1;
        }
    }
    return ans;
}

int main() {
    vector<int> i = {8,5,4,8,4};
    cout << maxTickets(i);
}
