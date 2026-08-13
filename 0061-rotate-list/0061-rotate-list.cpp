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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode* tail = head;
        int count = 1;

        while (tail->next != NULL) {
            tail = tail->next;
            count++;
        }
        k = k % count;
        if (k % count == 0)
            return head;
        tail->next = head;
        for (int i = 1; i < count - k; i++)
            head = head->next;
        ListNode* temp = head->next;
        head->next = NULL;
        head = temp;
        return head;
    }
};