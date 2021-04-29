#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int size;
    string text;
    ListNode *next;

    ListNode(int x, string s) : size(x), text(s), next(nullptr) {}
};

char get(ListNode *node, int position) {
    ListNode *tmp = node;
    while (tmp) {
        if (position > tmp->size) {
            position -= tmp->size;
        } else {
            return tmp->text[position - 1];
        }
        tmp = tmp->next;
    }
}

int main() {
    ListNode *head = new ListNode(3, "adc");
    head->next = new ListNode(4, "qwer");
    cout << get(head, 8);
    return 0;
}
