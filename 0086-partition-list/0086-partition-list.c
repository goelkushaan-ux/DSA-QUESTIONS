/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode *first = NULL, *sec = NULL, *temp = head, *h2;
    while (temp != NULL) {
        struct ListNode *next = temp->next;
        if (temp->val < x) {
            if (first == NULL) {
                first = temp;
                head = first;
            } else {
                first->next = temp;
                first = first->next;
            }
        } else {
            if (sec == NULL) {
                sec = temp;
                h2 = sec;
            } else {
                sec->next = temp;
                sec = sec->next;
            }
        }
        temp =next;
    }
    if (first == NULL) {
            sec->next = NULL;
        return h2;
    }
    first->next = h2;
    if (sec != NULL)
        sec->next = NULL;
    return head;
}