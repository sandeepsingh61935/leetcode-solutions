/**
 * @file remove-duplicates-from-sorted-list.cpp
 * @author sandeep singh     (sandeepss128961@gmail.com)
 * @brief Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
 * @version 0.1
 * @date 2022-07-05
 * @copyright Copyright (c) 2022
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* cur = head;
        ListNode* next = head->next;
        while(next && cur->val == next->val) {
            ListNode* temp = next;
            next = next->next;
            delete(temp);
        }
        cur->next = deleteDuplicates(next);
        return head;
    }
};