/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
@problem statement:
Given a Linked List A consisting of N nodes.

The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.

You need to sort the linked list and return the new linked list.
*/
ListNode* Solution::solve(ListNode* A) {
    int ones = 0;
    int zeros = 0;
    ListNode* cur = A;

    while(cur) {
        if (cur->val) ones++;
        else zeros++;
        cur = cur->next;
    }

    cur = A;
    while(zeros--) {
        cur->val = 0;
        cur = cur->next;
    }
    while(ones--)
    {
        cur->val =1 ;
        cur =cur->next;
    }
    return A;
}
