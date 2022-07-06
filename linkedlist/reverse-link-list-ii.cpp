/**
 * @file reverse-link-list-ii.cpp
 * @author your name (you@domain.com)
 * @brief  
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * @problem description : 
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.

    For example:

    Given 1->2->3->4->5->NULL, m = 2 and n = 4,

    return 1->4->3->2->5->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
   ListNode *curr = head, *prev = NULL;
    // prev points to the node before mth node
    int i;
    for (i = 1; i < m; i++) {
        prev = curr;
        curr = curr->next;
    }
    // This pointer stores the pointer to the head of the
    // reversed linkedlist
    ListNode* rtail = curr;
    // This pointer stores the pointer to the tail of the
    // reversed linkedlist
    ListNode* rhead = NULL;
    // Now reverse the linked list from m to n nodes
    while (i <= n) {
        ListNode* next = curr->next;
        curr->next = rhead;
        rhead = curr;
        curr = next;
        i++;
    }
    // if prev is not null it means that some of the nodes
    // exits before m  or we can say m!=1
    if (prev != NULL)
        prev->next = rhead;
    else
        head = rhead;
    // at this point curr will point to the next of nth
    // node where we will connect the tail of the reversed
    // linked list
    rtail->next = curr;
    // at the end return the new head.
    return head;

}
