/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *temp = head, *prev = NULL;
    while (temp != NULL)
    {
        if (temp->val == val)
        {
            if (temp == head)
            {
                head = temp->next;
                temp = head;
            }
            else
            {
                prev->next = temp->next;
                temp = prev->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}