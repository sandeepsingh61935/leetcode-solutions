/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* head) {
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
    prev = NULL;
    ListNode* cur = fast;
    while(cur != NULL) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    // merge the two lists alternatively

    ListNode* cur1 = head;
    ListNode* cur2 = prev;
    while(cur1 && cur2) {
        ListNode* next1 = cur1->next;
        ListNode* next2 = cur2->next;
        cur1->next = cur2;
        cur2->next = next1;
        cur1 = next1;
        cur2 = next2;
    }
    return head;
}
