/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* cur = head;
    while(cur) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
ListNode* Solution::subtract(ListNode* head) {
    if (!head || !head->next) return head; 
     ListNode* slow = head; 
    ListNode* fast= head;
    ListNode* prev = NULL;
    while(fast && fast->next) {
        prev =slow ;
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* middle = slow;
    if (fast == NULL)  {
        // even nodes 
        middle = prev;
    }
    slow = head ;
    fast = middle->next;
    middle->next = NULL;
    // reverse the fast list
    prev = reverseList(fast);
    // merge the two lists based on given constraint

    ListNode* cur1 = head;
    ListNode* cur2 = prev;
    ListNode* prev1 = NULL;
    while(cur1 && cur2) {
        ListNode* next1 = cur1->next;
        ListNode* next2 = cur2->next;
        cur1->val = cur2->val - cur1->val;
        prev1 = cur1;
        cur1 = next1;
        cur2 = next2;
    }
    if (!cur1)
        prev1->next = reverseList(prev);
    else cur1->next = reverseList(prev);
    return head;
}
';'