/**
 * @file remove-nth-node-from-list-end.cpp
 * @author sandeepsingh  (sandeepss128961@gmail.com)
 * @brief Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // count no. of nodes in list
        int len = 0 ; 
        ListNode* cur = head;
        while(cur) {
            len++;
            cur = cur->next;
        }

        int index = len - n;
        if (index ==0) {
            return head->next;
        }
        // index points to the node to be deleted
        cur = head;
        ListNode* prev =cur;
        while(cur && index--) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        return head;
    }
};