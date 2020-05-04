#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* head = NULL;
int length = 0;

void insert_node(int position, int value) {
    // @params position, integer
    // @params value, integer
    if(position>length+1)
        return;
    ListNode* node = new ListNode(value);
    ListNode* tmp = head;
    ListNode* prev = NULL;
    for(int i = 1;i<position; i++){
        prev=tmp;
        tmp=tmp->next;
    }
    if(tmp==head){
        head=node;
        head->next=tmp;
    }
    else{
        prev->next=node;
        node->next=tmp;
    }
    length++;
}

void delete_node(int position) {
    // @params position, integer
    if(position>length)
        return;
    ListNode* tmp = head;
    ListNode* prev = NULL;
    for(int i = 1;i<position; i++){
        prev=tmp;
        tmp=tmp->next;
    }
    if(tmp==head){
        head=head->next;
    }
    else{
        prev->next=prev->next->next;
    }
    length--;
}


void print_ll() {
    // Output each element followed by a space
    ListNode* tmp = head;
    string delimiter = "";
    while(tmp!=NULL){
        cout << delimiter << tmp->val;
        delimiter = " ";
        tmp=tmp->next;
    }
}