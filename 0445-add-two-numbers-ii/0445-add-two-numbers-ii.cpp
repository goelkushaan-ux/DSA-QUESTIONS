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
        ListNode* prevnode = nullptr;
        ListNode* currentnode = head;
        ListNode* nextnode = head;

        while (nextnode != nullptr) {
            nextnode = nextnode->next;
            currentnode->next = prevnode;
            prevnode = currentnode;
            currentnode = nextnode;
        }

        return prevnode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int n1 = 0, n2 = 0;
        while (temp1 != nullptr) {
            n1++;
            temp1 = temp1->next;
        }

        while (temp2 != nullptr) {
            n2++;
            temp2 = temp2->next;
        }
        if (n2 > n1)
            swap(l1, l2);
        temp1 = l1;
        temp2 = l2;
        ListNode* prev = nullptr;
        int carry = 0;

        while (temp1 != nullptr) {
            int sum = carry;
            sum += temp1->val;
            if (temp2 != nullptr) {
                sum += temp2->val;
                temp2 = temp2->next;
            }
            temp1->val = sum % 10;
            carry = sum / 10;
            prev = temp1;
            temp1 = temp1->next;
        }
        if (carry != 0)
            prev->next = new ListNode(carry);
        return reverseList(l1);
    }
};