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
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *cur = head;
        while (cur != NULL) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1)
            return head;
        ListNode *prev = head, *cur = head, *next = head, *groupPrevTail = NULL;
        while (next != NULL) {
            int i;
            for (i = 1; i < k && next != NULL; i++)
                next = next->next;
            if (i == k && next != NULL) {
                cur = next;
                next = next->next;
                cur->next = NULL;
                ListNode* newSubHead = reverse(prev);
                if (prev == head)
                    head = newSubHead;
                else
                    groupPrevTail->next = newSubHead;

                groupPrevTail = prev;
                prev->next = next;
                prev = next;
                cur = next;
            } else
                break;
        }
        return head;
    }
};