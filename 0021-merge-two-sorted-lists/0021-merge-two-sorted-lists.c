/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
  struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode)); 
    struct ListNode *temp = dummy; 
struct ListNode *h1 =list1,*h2=list2;
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->val <= h2->val)
        {
            temp->next = h1;
            h1 = h1->next;
        }
        else
        {
            temp->next = h2;
            h2 = h2->next;
        }
        temp = temp->next;
    }

    if (h1 != NULL)
        temp->next = h1;
    else
        temp->next = h2;

struct ListNode *head = dummy->next; 
    free(dummy);
    return head;
}