/*
    21. Merge Two Sorted Lists

    You are given the heads of two sorted linked lists list1 and list2.

    Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

    Return the head of the merged linked list.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 ) return list2;
        if (!list2 ) return list1;

        ListNode* last = new ListNode();
        ListNode* head = last;
        ListNode* h1  = list1 ;
        ListNode* h2  = list2 ;

        while(h1 && h2) {

            if (h1->val < h2->val) {
                last->next = h1;
                h1 = h1->next;
            } else {
                last->next = h2;
                h2 = h2->next;
            }
            last = last->next;
        }
 
        while(h1) {
            last->next = h1;
            h1 = h1->next;
            last = last->next;
        }


        while(h2) {
            last->next = h2;
            h2 = h2->next;
            last = last->next;
        }

        return head->next;


    }
};