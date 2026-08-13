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

    void reorderList(ListNode* head) {
        if (head->next == NULL || head->next->next == NULL)
            return;
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* h2 = reverseList(slow->next);
        slow->next = NULL;
        ListNode *temp1 = head, *temp2 = h2;
        slow = head;
        while (temp2 != NULL) {
            ListNode* next1 = temp1->next;
            ListNode* next2 = temp2->next;

            slow->next = temp2;
            temp2->next = next1;

            slow = next1;
            temp1 = next1;
            temp2 = next2;
        }
       if(slow!=NULL) slow->next = NULL;
    }
};