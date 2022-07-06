/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// @brief: Given a linked list A of length N and an integer B.

// You need to find the value of the Bth node from the middle towards the beginning of the Linked List A.

// If no such element exists, then return -1.
int Solution::solve(ListNode* head, int n) {
    if (!head) return -1 ;
    ListNode* cur = head;
    int middleIndex = 0 ;
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        middleIndex++;
    }

    if (n > middleIndex) return -1;

    for (int i = 0; i < middleIndex - n; i++)
        cur = cur->next;
    return cur->val;
}
