/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::deleteDuplicates(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *cur = head;
    ListNode *prev = new ListNode(0);
    ListNode *next = head->next;
    int cnt = 0;
    while (next && cur->val == next->val)
    {
        ListNode *temp = next;
        next = next->next;
        cnt++;
        delete (temp);
    }
    if (cnt)
    {
        prev->next = deleteDuplicates(next);
        return prev->next;
    }
    cur->next = deleteDuplicates(next);
    return head;
}
