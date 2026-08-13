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
    ListNode* reverseList(ListNode* head) {
        ListNode *prevnode, *currentnode, *nextnode;

        prevnode = nullptr;
        currentnode = head;
        nextnode = head;

        while (nextnode != nullptr) {
            nextnode = nextnode->next;
            currentnode->next = prevnode;
            prevnode = currentnode;
            currentnode = nextnode;
        }
        return prevnode;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head->next == NULL || left == right)
            return head;
        if (left == 1) {
            ListNode* next = head;
            for (int i = 1; i < right; i++)
                next = next->next;
            ListNode* after = next->next;
            next->next = nullptr;
            head = reverseList(head);
            ListNode* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = after;
            return head;
        }
        ListNode *start = NULL, *temp = head;
        for (int i = 1; temp != NULL; i++) {
            if (i < left)
                start = temp;
            if (i == right) {
                ListNode* next = temp->next;
                temp->next = NULL;
                start->next = reverseList(start->next);
                while (start->next != NULL)
                    start = start->next;
                start->next = next;
                return head;
            }
            temp = temp->next;
        }
        return head;
    }
};