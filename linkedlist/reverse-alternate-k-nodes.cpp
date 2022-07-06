/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/***
 * @problem description:
 * Given a linked list A of length N and an integer B.
 * You need to reverse every alternate B nodes in the linked list A.
 * Input 1:

 A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
 B = 3
 Input 2:

 A = 1 -> 4 -> 6 -> 6 -> 4 -> 10
 B = 2



 Output 1:

 7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15
Output 2:

 4 -> 1 -> 6 -> 6 -> 10 -> 4
 */

ListNode *Solution::solve(ListNode *head, int k)
{
    ListNode *current = head;
    ListNode *next;
    ListNode *prev = NULL;
    int count = 0;

    /*1) reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    /* 2) Now head points to the kth node.
    So change next  of head to (k+1)th node*/
    if (head != NULL)
        head->next = current;

    /* 3) We do not want to reverse next k
       nodes. So move the current
        pointer to skip next k nodes */
    count = 0;
    while (count < k - 1 && current != NULL)
    {
        current = current->next;
        count++;
    }

    /* 4) Recursively call for the list
    starting from current->next. And make
    rest of the list as next of first node */
    if (current != NULL)
        current->next = solve(current->next, k);

    /* 5) prev is new head of the input list */
    return prev;
}
