/**
 * @file linked-list-cycle.cpp
 * @author sandeep singh (sandeepss128961@gmail.com)
 * @brief Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* rabbit = head->next;
        ListNode* turtle = head;
 
        while(rabbit != turtle) {
            if (!rabbit || !rabbit->next) return false;
            rabbit = rabbit->next->next;
            turtle = turtle->next;
        }
        return true;
    }
};