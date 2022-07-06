/**
 * @file palindrome-linked-list.cpp
 * @author sandeep singh (sandeepss128961@gmail.com)
 * @brief Given the head of a singly linked list, return true if it is a palindrome.
 * @version 0.1
 * @date 2022-07-05
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev= NULL;
        ListNode* cur = head;
        ListNode* next = NULL;

        while(cur) {
            next = cur->next;
            cur->next = prev ;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        // single node list is palindrome
        if (!head || !head->next) return true;

        // find the middle of the list

        ListNode* rabbit = head;
        ListNode* turtle = head;

        while(rabbit && rabbit->nex->next) {
            rabbit = rabbit->next->next;
            turtle = turtle->next;
        }

        // rverse the second half of the list
        ListNode* secondHalf = turtle;
        if (rabbit)
            secondHalf = turtle->next;
        secondHalf = reverseList(secondHalf);
        firstHalf = head;
        while(secondHalf) {
            if (firstHalf->val != secondHalf->val) return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;

    }
};