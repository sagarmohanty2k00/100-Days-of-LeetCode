#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() {
        this->val = 0;
        this->next = NULL;
    }
    ListNode(int x) {
        this->val = x;
        this->next = NULL;
    }
};


class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *p = NULL;
        ListNode *c = head;
        ListNode *n = head->next;

        while (c != NULL) {
            c ->next = p;
            p = c;
            c = n;

            if (n != NULL) n = n->next;
        }

        return p;
    }
    void reorderList(ListNode* head) {
        ListNode *ptr = head;
        while (ptr != NULL and ptr->next != NULL) {
            ptr->next = reverse(ptr->next);
            ptr = ptr->next;
        }
    }
};


int main() {
    // ListNode *head = NULL;
    // ListNode *tail = NULL;

    // int list_size;
    // cin >> list_size;

    // for (int i=0; i<list_size; i++) {
    //     int val; cin >> val;

    //     ListNode *ptr = new ListNode(val);
    //     if (head == NULL) {
    //         head = ptr;
    //         tail = ptr;
    //     }
    //     else {
    //         tail->next = ptr;
    //         tail = tail->next;
    //     }
    // }

    // Solution ob;
    // ob.reorderList(head);
    // while (head != NULL) {
    //     cout << head->val << " ";
    //     head = head->next;
    // }
    // cout << endl;


    int gender = 1;
    if (gender == 1)
        puts( "Woman" );
    else;
        puts( "Man" );
}