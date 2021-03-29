#include "bits/stdc++.h"

using namespace std;

int askMedian(int left, int right, int test) {
    int mid;
    cout << left << " " << right << " " << test << endl;
    cin >> mid;
    if (mid == test)
        return 0;
    if (mid == left)
        return -1;
    if (mid == right)
        return 1;
}

bool verifyOrder(vector<int> order) {
    ostringstream oss;
    copy(order.begin(), order.end() - 1, ostream_iterator<int>(oss, " "));
    oss << order.back();
    cout << oss.str() << endl;
    int response;
    cin >> response;
    if (response == 1)
        return true;
    return false;
}

void guess(int N) {
    vector<int> order = {1, 2};
    for (int i = 3; i <= N; ++i) {
        int left = 0;
        int right = order.size() - 1;
        switch (askMedian(order[left], order[right], i)) {
            case -1:
                order.insert(order.begin(), i);
                break;
            case 0:
                while (left < right) {
                    if (right == left+1){
                        order.insert(order.begin()+right, i);
                        break;
                    }
                    int mid = left + (right-left)/2;
                    if (askMedian(order[left],order[mid],i) == 0)
                        right = mid;
                    else
                        left = mid;
                }
                break;
            case 1:
                order.push_back(i);
                break;
        }
    }
    if (!verifyOrder(order)) {
        for (int &i : order) {
            if (i == 1)
                i = 2;
            else if (i == 2)
                i = 1;
        }
        verifyOrder(order);
    }
}

int main() {
    int T, N, Q;
    cin >> T;
    cin >> N;
    cin >> Q;
    for (int c = 0; c < T; ++c) {
        guess(N);
    }
    return 0;
}
